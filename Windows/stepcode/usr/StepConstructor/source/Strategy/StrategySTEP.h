#pragma once

#include		<Registry.h>
#include		<STEPfile.h>
#include		<sdai.h>
#include		<schema.h>
#include		<STEPattribute.h>

#include		"MeshModel.h"

#include		<Windows.h>
#include		<stdio.h>
#include		<gdiplus.h>
using namespace Gdiplus;

#include		<boost/property_tree/ptree.hpp>
#include		<boost/property_tree/json_parser.hpp>
#include		<boost/optional.hpp>

namespace Strategy {

	class StrategySTEP {
	public:
		std::string _rootpath;
		boost::property_tree::ptree _jsonsetting;
	public:
		StrategySTEP();
		StrategySTEP(const StrategySTEP& obj);
		virtual ~StrategySTEP();

		virtual void ParseJSONSetting(boost::property_tree::ptree& setting_ptree);
		virtual int AnalyzeMeshModel(MeshModel& model);
		virtual int Export(std::string rootdir, Bitmap* pBitmap);
	};
}


