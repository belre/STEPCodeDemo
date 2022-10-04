
#include		"main.h"
#include		<iostream>
#include		<sstream>

#include		<vector>

#include		<Registry.h>
#include		<STEPfile.h>
#include		<sdai.h>
#include		<schema.h>
#include		<STEPattribute.h>




void PrintCartesianPoint(const SDAI_Application_instance* ancestor, const SdaiCartesian_point* cartesian_inst) {
	string expression_str;
	if (cartesian_inst != NULL) {
		RealAggregate_ptr_c aggr_param = cartesian_inst->coordinates_();
		RealNode* iter_realnode = dynamic_cast<RealNode*>(aggr_param->GetHead());

		std::cout << "#" << cartesian_inst->FileId() << ",Cartesian Point,";
		for (; iter_realnode != NULL; iter_realnode = dynamic_cast<RealNode*>(iter_realnode->next)) {
			std::cout << iter_realnode->asStr(expression_str) << ",";
		}
		std::cout << "#" << ancestor->FileId() << "," << ancestor->EntityName();
		std::cout << std::endl;
	}
}



void PrintVector(const SDAI_Application_instance* ancestor, const SdaiVector* vector_inst) {
	string expression_str;
	if (vector_inst != NULL) {
		RealAggregate_ptr_c aggr_param = vector_inst->orientation_()->direction_ratios_();
		SdaiLength_measure magnitude = vector_inst->magnitude_();
		RealNode* iter_realnode = dynamic_cast<RealNode*>(aggr_param->GetHead());

		std::cout << "#" << vector_inst->FileId() << ",Vector,";
		for (; iter_realnode != NULL; iter_realnode = dynamic_cast<RealNode*>(iter_realnode->next)) {
			std::cout << iter_realnode->asStr(expression_str) << ",";
		}
		std::cout << magnitude << ",";

		std::cout << "#" << ancestor->FileId() << "," << ancestor->EntityName();
		std::cout << std::endl;
	}
}

void PrintBSplineCurveWithKnots(const SDAI_Application_instance* ancestor, const SdaiB_spline_curve_with_knots* spline_inst) {
	string expression_str;
	if (spline_inst != NULL) {
		stringstream ss_prefix;
		ss_prefix << "#" << spline_inst->FileId() << ",B Spline Curve With Knots,";

		stringstream ss_postfix;
		ss_postfix << "#" << ancestor->FileId() << "," << ancestor->EntityName() << std::endl;

		std::cout << ss_prefix.str();
		std::cout << spline_inst->degree_() << ",";
		std::cout << ss_postfix.str();

		const EntityAggregate* entityaggr = dynamic_cast<const EntityAggregate*>(spline_inst->control_points_list_());
		const EntityNode* entitynode = dynamic_cast<const EntityNode*>(entityaggr->GetHead());
		for (; entitynode != NULL; entitynode = dynamic_cast<const EntityNode*>(entitynode->next)) {
			SdaiCartesian_point* node_cartesian = dynamic_cast<SdaiCartesian_point*>(entitynode->node);
			PrintCartesianPoint(ancestor, node_cartesian);
		}

		std::cout << ss_prefix.str();
		std::cout << spline_inst->curve_form_().asStr(expression_str) << ",";
		std::cout << (spline_inst->closed_curve_() ? "T" : "F") << "," << (spline_inst->self_intersect_() ? "T" : "F") << "," ;
		std::cout << ss_postfix.str();

		std::cout << ss_prefix.str();
		const IntAggregate* knotmultip = spline_inst->knot_multiplicities_();
		const IntNode* intnode = dynamic_cast<const IntNode*>(knotmultip->GetHead());
		for (; intnode != NULL; intnode = dynamic_cast<const IntNode*>(intnode->next)) {
			std::cout << intnode->value << ",";
		}

		const RealAggregate* knotsaggr = spline_inst->knots_();
		const RealNode* realnode = dynamic_cast<const RealNode*>(knotsaggr->GetHead());
		for (; realnode != NULL; realnode = dynamic_cast<const RealNode*>(realnode->next)) {
			std::cout << realnode->value << ",";
		}
		std::cout << spline_inst->knot_spec_().asStr(expression_str) << ",";
		std::cout << ss_postfix.str();
	}
}

double CalculateDiag(vector<double> matrix) {
	if (matrix.size() != 9) {
		return NAN;
	}

	double val = 0;
	val += matrix[0 * 3 + 0] * matrix[1 * 3 + 1] * matrix[2 * 3 + 2];
	val += matrix[1 * 3 + 0] * matrix[2 * 3 + 1] * matrix[0 * 3 + 2];
	val += matrix[2 * 3 + 0] * matrix[0 * 3 + 1] * matrix[1 * 3 + 2];
	val -= matrix[0 * 3 + 2] * matrix[1 * 3 + 1] * matrix[2 * 3 + 0];
	val -= matrix[1 * 3 + 2] * matrix[2 * 3 + 1] * matrix[0 * 3 + 0];
	val -= matrix[2 * 3 + 2] * matrix[0 * 3 + 1] * matrix[1 * 3 + 0];

	return val;
}

int main(int argv, char** argc)
{
	// Setting
	const double ROI_LOWER_RADIUS = 28.0;
	const double MIN_ERROR = 1e-10;


	Registry* registry = new Registry(SchemaInit);

	// The InstMgr holds instances that have been created or that have been loaded from a file
	InstMgr* instance_list = new InstMgr();

	// Increment FileId so entities start at #1 instead of #0.
	instance_list->NextFileId();

	// STEPfile takes care of reading and writing Part 21 files
	STEPfile* sfile = new STEPfile(*registry, *instance_list, "D:\\StepData\\BSP35B20-N-12.stp", false);

	// Define Vertex List
	StepGraph graph;
	std::vector<StepGraph::vertex_descriptor> vertex_list;

	string expressionstr;


	// Construct Vertex Point
	for (int i = 0; i < instance_list->InstanceCount(); i++) {
		// Set SDAI_Application_instance by Index
		SDAI_Application_instance* inst = instance_list->GetSTEPentity(i);

		// Extract all coordinates from vertex_point
		const SdaiVertex_point* vertex_inst = dynamic_cast<SdaiVertex_point*>(inst);
		if (vertex_inst == NULL) {
			continue;
		}

		// Get Attributes and refer cartesian point
		const SdaiCartesian_point* attr_cartesianpoint = dynamic_cast<const SdaiCartesian_point*>(vertex_inst->vertex_geometry_());
		if (attr_cartesianpoint == NULL) {
			continue;
		}
		
		double radius = 0;

		const RealAggregate* real_aggr = attr_cartesianpoint->coordinates_();
		const RealNode* x_coordinate = dynamic_cast<RealNode*>(real_aggr->GetHead());
		const RealNode* y_coordinate = dynamic_cast<RealNode*>(real_aggr->GetHead()->next);
		radius = sqrt(x_coordinate->value * x_coordinate->value + y_coordinate->value * y_coordinate->value);
		if (radius < ROI_LOWER_RADIUS) {
			continue;
		}


		RealAggregate_ptr_c aggr_param = attr_cartesianpoint->coordinates_();
		RealNode* iter_realnode = dynamic_cast<RealNode*>(aggr_param->GetHead());
		
		StepGraph::vertex_descriptor v = add_vertex(graph);
		graph[v]._fileid = inst->FileId();
		graph[v]._point._coordinate = { iter_realnode->value, dynamic_cast<RealNode*>(iter_realnode->next)->value, dynamic_cast<RealNode*>(iter_realnode->next->next)->value };
		vertex_list.push_back(v);
		//PrintCartesianPoint(inst, attr_cartesianpoint);
	}

	
	std::cout << "#####" << std::endl;

	// Construct elements as follows:
	// * Line
	// * B_Spline_Curve_With_Knots
	for (int i = 0; i < instance_list->InstanceCount(); i++) {
		// Set SDAI_Application_instance by Index
		SDAI_Application_instance* inst = instance_list->GetSTEPentity(i);
		int fileid = inst->FileId();

		const SdaiEdge_curve* edgecurve_inst = dynamic_cast<SdaiEdge_curve*>(inst);
		if (edgecurve_inst != NULL) {
			const SdaiVertex* vertex_start = edgecurve_inst->edge_start_();	
			const SdaiVertex_point* vertexpoint_start = dynamic_cast<const SdaiVertex_point*>(vertex_start);
			const SdaiCartesian_point* cartesian_start = dynamic_cast<const SdaiCartesian_point*>(vertexpoint_start->vertex_geometry_());
				

			const SdaiVertex* vertex_end = edgecurve_inst->edge_end_();
			const SdaiVertex_point* vertexpoint_end = dynamic_cast<const SdaiVertex_point*>(vertex_end);
			const SdaiCartesian_point* cartesian_end = dynamic_cast<const SdaiCartesian_point*>(vertexpoint_end->vertex_geometry_());

			auto iter_seek_vertex_start = find_if(vertex_list.begin(), vertex_list.end(), [vertex_start, graph](StepGraph::vertex_descriptor& dsc) { return graph[dsc]._fileid == vertex_start->FileId(); });
			auto iter_seek_vertex_end = find_if(vertex_list.begin(), vertex_list.end(), [vertex_end, graph](StepGraph::vertex_descriptor& dsc) { return graph[dsc]._fileid == vertex_end->FileId(); });

			if (iter_seek_vertex_start != vertex_list.end() && iter_seek_vertex_end != vertex_list.end()) {
				StepGraph::edge_descriptor e12;
				bool inserted = false;
				boost::tie(e12, inserted) = add_edge(*iter_seek_vertex_start, *iter_seek_vertex_end, graph);
			}
		}




#if 0

		// Cast
		const SdaiLine* line_inst = dynamic_cast<SdaiLine*>(inst);
		const SdaiB_spline_curve_with_knots* bsplinecurvewithknots_inst = dynamic_cast<SdaiB_spline_curve_with_knots*>(inst);

		if (line_inst != NULL) {
			const SdaiCartesian_point* attr_cartesianpoint = line_inst->pnt_();
			const SdaiVector* attr_dir = line_inst->dir_();

			double radius = 0;

			const RealAggregate* real_aggr = attr_cartesianpoint->coordinates_();
			const RealNode* x_coordinate = dynamic_cast<RealNode*>(real_aggr->GetHead());
			const RealNode* y_coordinate = dynamic_cast<RealNode*>(real_aggr->GetHead()->next);
			const RealNode* z_coordinate = dynamic_cast<RealNode*>(real_aggr->GetHead()->next->next);
			radius = sqrt(x_coordinate->value * x_coordinate->value + y_coordinate->value * y_coordinate->value);
			if (radius < ROI_LOWER_RADIUS) {
				continue;
			}
			vector<double> org_coordinate = { x_coordinate->value, y_coordinate->value, z_coordinate->value };

			real_aggr = attr_dir->orientation_()->direction_ratios_();
			vector<double> dir_vector;
			for (auto nodeiter = dynamic_cast<RealNode*>(real_aggr->GetHead()); nodeiter != NULL; nodeiter = dynamic_cast<RealNode*>(nodeiter->next)) {
				dir_vector.push_back(nodeiter->value);
			}
			SdaiLength_measure magnitude = attr_dir->magnitude_();

			// make destination of the line from org_coordinate along dir_vector and magnitude
			Point orgpoint;
			orgpoint._coordinate = org_coordinate;
			Point destpoint;
			for (int i = 0; i < org_coordinate.size(); i++) {
				destpoint._coordinate.push_back(org_coordinate[i] + magnitude * dir_vector[i]);
			}

			// Extract Vertices satisfied with condition of the line 
			vector<StepGraph::vertex_descriptor> extracted_vertices;
			std::for_each(vertex_list.begin(), vertex_list.end(),
				[&extracted_vertices, orgpoint, destpoint, graph](StepGraph::vertex_descriptor& c_vertex) {
					if (graph[c_vertex]._point.InRange(orgpoint, destpoint)) {
						extracted_vertices.push_back(c_vertex);
					}
				}
			);

			// Bind
			if (extracted_vertices.size() >= 2) {
				for (auto iter = extracted_vertices.begin() + 1; iter != extracted_vertices.end(); iter++) {
					StepGraph::edge_descriptor e;
					bool inserted = false;
					boost::tie(e, inserted) = add_edge(*(iter - 1), *iter, graph);
				}
			}

			//PrintCartesianPoint(inst, attr_cartesianpoint);
			//PrintVector(inst, attr_dir);
		} else if (bsplinecurvewithknots_inst != NULL) {


			const EntityAggregate* entityaggr = dynamic_cast<const EntityAggregate*>(bsplinecurvewithknots_inst->control_points_list_());
			const SdaiCartesian_point* entityhead = dynamic_cast<const SdaiCartesian_point*>(dynamic_cast<const EntityNode*>(entityaggr->GetHead())->node);
			const SdaiCartesian_point* entitytail = NULL;
			const SingleLinkNode* entitynode = entityaggr->GetHead();
			for (; entitynode != NULL; entitynode = entitynode->next) {
				entitytail = dynamic_cast<const SdaiCartesian_point*>(dynamic_cast<const EntityNode*>(entitynode)->node);				
			}

			// make destination of the line from org_coordinate along dir_vector and magnitude
			Point orgpoint;
			Point destpoint;
			const RealNode* headnode = dynamic_cast<const RealNode*>( entityhead->coordinates_()->GetHead());
			const RealNode* tailnode = dynamic_cast<const RealNode*>( entitytail->coordinates_()->GetHead());
			for (; headnode != NULL && tailnode != NULL; headnode = dynamic_cast<const RealNode*>(headnode->next), tailnode = dynamic_cast<const RealNode*>(tailnode->next) ) {
				orgpoint._coordinate.push_back(headnode->value);
				destpoint._coordinate.push_back(tailnode->value);
			}

			// Extract Vertices satisfied with condition of the line 
			vector<StepGraph::vertex_descriptor> extracted_vertices;
			std::for_each(vertex_list.begin(), vertex_list.end(),
				[&extracted_vertices, orgpoint, destpoint, MIN_ERROR, graph](StepGraph::vertex_descriptor& c_vertex) {
					if (graph[c_vertex]._point.InRange(orgpoint, destpoint, MIN_ERROR)) {
						extracted_vertices.push_back(c_vertex);
					}
				}
			);

			// Bind
			if (extracted_vertices.size() >= 2) {
				for (auto iter = extracted_vertices.begin() + 1; iter != extracted_vertices.end(); iter++) {
					StepGraph::edge_descriptor e;
					bool inserted = false;
					boost::tie(e, inserted) = add_edge(*(iter - 1), *iter, graph);
				}
			}
		}
#endif

	}

	std::cout << "#####" << std::endl;

	for (int i = 0; i < vertex_list.size(); i++) {
		std::cout << i << "," << graph[vertex_list[i]]._point._coordinate[0] << "," << graph[vertex_list[i]]._point._coordinate[1] << "," << graph[vertex_list[i]]._point._coordinate[2] << std::endl;
	}

	std::cout << "#####" << std::endl;

	boost::print_graph(graph);

	return 0;
}
