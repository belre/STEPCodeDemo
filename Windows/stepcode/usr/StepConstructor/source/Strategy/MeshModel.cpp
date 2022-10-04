
#include		"MeshModel.h"
#include		<sdai.h>
#include		<schema.h>

using namespace Strategy;

#include		"GraphDefinitionForBoost.h"
#include		"ConcreteCurveEdgeGeometry.h"


MeshModel::MeshModel() :_graph(STEPMeshGraph()) {

}


MeshModel::MeshModel(const MeshModel& obj) : _graph(STEPMeshGraph()) {

}

MeshModel::~MeshModel() {

}

int MeshModel::ParseSTEPFile(STEPfile& file, InstMgr& instance_list, boost::property_tree::ptree& jsonsetting) {

	double roi_lower_radius = ROI_LOWER_RADIUS;
	if (boost::optional<double> optional = jsonsetting.get_optional<double>("STEPExtractor.radius")) {
		roi_lower_radius = optional.get();
	}

	auto swap_AxisPoint = [](Vector3d org) {
		Vector3d dest(org);
		dest._coordinate[0] = org._coordinate[1];
		dest._coordinate[1] = org._coordinate[2];
		dest._coordinate[2] = org._coordinate[0];
		return dest;
	};


	STEPMeshGraph graph;

	graph[boost::graph_bundle]._name = file.FileName();

	std::vector<STEPMeshGraph::vertex_descriptor> vertex_list;

	for (int i = 0; i < instance_list.InstanceCount(); i++) {
		// Set SDAI_Application_instance by Index
		SDAI_Application_instance* inst = instance_list.GetSTEPentity(i);

		// Extract all coordinates from vertex_Point
		const SdaiVertex_point* vertex_inst = dynamic_cast<SdaiVertex_point*>(inst);
		if (vertex_inst == NULL) {
			continue;
		}

		// Get Attributes and refer cartesian Vector3d
		const SdaiCartesian_point* attr_cartesianPoint = dynamic_cast<const SdaiCartesian_point*>(vertex_inst->vertex_geometry_());
		if (attr_cartesianPoint == NULL) {
			continue;
		}

		RealAggregate_ptr_c aggr_param = attr_cartesianPoint->coordinates_();
		RealNode* iter_realnode = dynamic_cast<RealNode*>(aggr_param->GetHead());

		Vector3d currentpoint;
		currentpoint._coordinate = { iter_realnode->value, dynamic_cast<RealNode*>(iter_realnode->next)->value, dynamic_cast<RealNode*>(iter_realnode->next->next)->value };
		currentpoint = swap_AxisPoint(currentpoint);

		double radius = 0;
		//const RealAggregate* real_aggr = attr_cartesianPoint->coordinates_();
		double x_coordinate = currentpoint[0];
		double y_coordinate = currentpoint[1];
		radius = sqrt(x_coordinate * x_coordinate + y_coordinate * y_coordinate);		
		if (radius < roi_lower_radius) {
			continue;
		}

		STEPMeshGraph::vertex_descriptor v = add_vertex(graph);
		graph[v]._fileid = inst->FileId();
		graph[v]._Point = currentpoint;
		vertex_list.push_back(v);
	}


	// Construct elements as follows:
	// * SdaiEdge_curve
	for (int i = 0; i < instance_list.InstanceCount(); i++) {
		// Set SDAI_Application_instance by Index
		SDAI_Application_instance* inst = instance_list.GetSTEPentity(i);
		int fileid = inst->FileId();

		const SdaiEdge_curve* edgecurve_inst = dynamic_cast<SdaiEdge_curve*>(inst);
		if (edgecurve_inst != NULL) {
			const SdaiVertex* vertex_start = edgecurve_inst->edge_start_();
			const SdaiVertex_point* vertexPoint_start = dynamic_cast<const SdaiVertex_point*>(vertex_start);
			const SdaiCartesian_point* cartesian_start = dynamic_cast<const SdaiCartesian_point*>(vertexPoint_start->vertex_geometry_());


			const SdaiVertex* vertex_end = edgecurve_inst->edge_end_();
			const SdaiVertex_point* vertexPoint_end = dynamic_cast<const SdaiVertex_point*>(vertex_end);
			const SdaiCartesian_point* cartesian_end = dynamic_cast<const SdaiCartesian_point*>(vertexPoint_end->vertex_geometry_());

			const SdaiCircle* curve_circle_geometry = dynamic_cast<const SdaiCircle*>(edgecurve_inst->edge_geometry_());


			auto iter_seek_vertex_start = find_if(vertex_list.begin(), vertex_list.end(), [vertex_start, graph](STEPMeshGraph::vertex_descriptor& dsc) { return graph[dsc]._fileid == vertex_start->FileId(); });
			auto iter_seek_vertex_end = find_if(vertex_list.begin(), vertex_list.end(), [vertex_end, graph](STEPMeshGraph::vertex_descriptor& dsc) { return graph[dsc]._fileid == vertex_end->FileId(); });

			if (iter_seek_vertex_start != vertex_list.end() && iter_seek_vertex_end != vertex_list.end()) {
				STEPMeshGraph::edge_descriptor e12;
				bool inserted = false;
				boost::tie(e12, inserted) = add_edge(*iter_seek_vertex_start, *iter_seek_vertex_end, graph);

				// The specified curve-geometrical instance 
				if (curve_circle_geometry != NULL) {
					const SdaiAxis2_placement* selector = dynamic_cast<const SdaiAxis2_placement*>(curve_circle_geometry->position_());
					if (selector == NULL) {
						continue;
					}

					const SdaiCartesian_point* cartesian_axis = dynamic_cast<const SdaiCartesian_point*>(selector->location_());
					const SdaiDirection* direction_axis = dynamic_cast<const SdaiDirection*>(selector->axis_());
					const SdaiDirection* direction_ref = dynamic_cast<const SdaiDirection*>(selector->ref_direction_());

					const RealAggregate* cartesian_axis_aggr = cartesian_axis->coordinates_();
					const RealAggregate* direction_axis_aggr = direction_axis->direction_ratios_();
					const RealAggregate* direction_ref_aggr = direction_ref->direction_ratios_();
					
					CircleEdgeGeometry* geometry = new CircleEdgeGeometry();
					geometry->_center0._coordinate = { ((const RealNode*)cartesian_axis_aggr->GetHead())->value, 
													  ((const RealNode*)cartesian_axis_aggr->GetHead()->next)->value, 
													  ((const RealNode*)cartesian_axis_aggr->GetHead()->next->next)->value };

					geometry->_center0 = swap_AxisPoint(geometry->_center0);

					geometry->_normal_vector._coordinate = { ((const RealNode*)direction_axis_aggr->GetHead())->value,
															((const RealNode*)direction_axis_aggr->GetHead()->next)->value,
															((const RealNode*)direction_axis_aggr->GetHead()->next->next)->value };
					geometry->_normal_vector = swap_AxisPoint(geometry->_normal_vector);


					geometry->_first_ref_vector._coordinate = { ((const RealNode*)direction_ref_aggr->GetHead())->value,
																((const RealNode*)direction_ref_aggr->GetHead()->next)->value,
																((const RealNode*)direction_ref_aggr->GetHead()->next->next)->value };
					geometry->_first_ref_vector = swap_AxisPoint(geometry->_first_ref_vector);
					geometry->_second_ref_vector = geometry->_normal_vector.CrossProduct(geometry->_first_ref_vector);
					geometry->_second_ref_vector = swap_AxisPoint(geometry->_second_ref_vector);


					geometry->_radius = curve_circle_geometry->radius_();
					graph[e12]._geometry = geometry;
				} else {
					LineEdgeGeometry* geometry = new LineEdgeGeometry();
					graph[e12]._geometry = geometry; //LineEdgeGeometry();
				}

				//std::cout << (int)(graph[e12]._geometry.GetType()) << std::endl;
			}
		}
	}

	_graph = graph;

	return 0;
}



