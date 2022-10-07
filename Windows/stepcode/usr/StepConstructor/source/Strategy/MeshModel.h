#pragma once

#include		<STEPfile.h>
#include		"GraphDefinitionForBoost.h"

#include		<boost/property_tree/ptree.hpp>
#include		<boost/property_tree/json_parser.hpp>
#include		<boost/optional.hpp>

namespace Strategy {



	class MeshModel {
	public:
		std::string _name;

		const double ROI_LOWER_RADIUS = 28.0;
		const double MIN_ERROR = 1e-10;
		STEPMeshGraph _graph;
		std::map<int, STEPMeshGraph::edge_descriptor> _closed_loop;

	public:
		MeshModel();
		MeshModel(const MeshModel& obj);
		~MeshModel();

		int ParseSTEPFile(STEPfile& file, InstMgr& instance_list, boost::property_tree::ptree& jsonsetting );
		void ExportGraph(string path);
	};





}
