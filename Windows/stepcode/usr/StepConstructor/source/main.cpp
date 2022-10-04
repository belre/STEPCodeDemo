
#include		"main.h"
#include		<iostream>
#include		<sstream>

#include		<vector>

#include		<Registry.h>
#include		<STEPfile.h>
#include		<sdai.h>
#include		<schema.h>
#include		<STEPattribute.h>

#include		"Strategy/StrategyStep.h"
#include		"Strategy/MeshModel.h"
#include		"Strategy/Circular/CenterZPlotting.h"
#include		"Strategy/Circular/WidenZPlotting.h"
#include		"Strategy/Circular/ZSliceImaging.h"



#include		<boost/property_tree/ptree.hpp>
#include		<boost/property_tree/json_parser.hpp>
#include		<boost/optional.hpp>

using namespace Strategy;
using namespace Strategy::Circular;

int main(int argv, char** argc)
{
	std::string steppath;
	std::string exportpath;
	std::string jsonpath(".\\jsonsetting.json");
	if (argv <= 2) {
		std::cerr << "Warning : argument invalid" << std::endl;
		std::cerr << "This program sets the default filename as step file." << std::endl << std::endl;

		std::cerr << "**************************" << std::endl;
		std::cerr << "Command Example:" << std::endl;
		std::cerr << "StepConstructor.exe test.stp ./" << std::endl;
		std::cerr << "**************************" << std::endl << std::endl;

		steppath = "D:\\StepData\\KANA_NK35B10D9_K.stp";
		exportpath = "D:\\StepData\\";
	} else if (argv <= 3) {
		steppath = string(argc[1]);
		exportpath = string(argc[2]);
	} else {
		steppath = string(argc[1]);
		exportpath = string(argc[2]);
		jsonpath = string(argc[3]);
	}

	// Load Parameters by Setting File
	boost::property_tree::ptree jsonsetting_ptree;
	boost::property_tree::read_json(jsonpath, jsonsetting_ptree);


	// #################################### //
	// Read STEP File
	// The registry contains information about types present in the current schema; SchemaInit is a function in the schema-specific SDAI library
	Registry* registry = new Registry(SchemaInit);

	// The InstMgr holds instances that have been created or that have been loaded from a file
	InstMgr* instance_list = new InstMgr();

	// Increment FileId so entities start at #1 instead of #0.
	instance_list->NextFileId();

	// STEPfile takes care of reading and writing Part 21 files
	STEPfile* sfile = new STEPfile(*registry, *instance_list, steppath, false);
	
	// Construct vertex and mesh based on STEP File
	STEPMeshGraph graph;
	MeshModel meshmodel;
	if (meshmodel.ParseSTEPFile(*sfile, *instance_list, jsonsetting_ptree) != 0) {
		return -1;
	}
	


	// #################################### //

	// If the loading was succeeded, analyze step Data.
	// The method how to analyse is different but the procedures are similar : supposed to implement strategy patterns
	// Method:
	// [1] z-center plot
	// [2] x-y image
	// Procedures:
	// (1) Analyze coordinates from step model
	// (2) Export Csv or Bmp(gdiplus.dll)
	vector<StrategySTEP*> _strategy_sequence;
	//_strategy_sequence.push_back(new CenterZPlotting());
	_strategy_sequence.push_back(new WidenZPlotting());
	_strategy_sequence.push_back(new ZSliceImaging());
	for (auto iter_strategy = _strategy_sequence.begin(); iter_strategy != _strategy_sequence.end(); iter_strategy++) {
		((*iter_strategy))->_rootpath = exportpath;
		((*iter_strategy))->ParseJSONSetting(jsonsetting_ptree);

		if ((*iter_strategy)->AnalyzeMeshModel(meshmodel) == 0) {

		}
	}



	return 0;
}
