
#include		"StrategySTEP.h"
#include		"MeshModel.h"


using namespace Strategy;


StrategySTEP::StrategySTEP() {

}

StrategySTEP::StrategySTEP(const StrategySTEP& obj) {

}

StrategySTEP::~StrategySTEP() {

}

void StrategySTEP::ParseJSONSetting(boost::property_tree::ptree& setting_ptree) {
	_jsonsetting = setting_ptree;
}

int StrategySTEP::AnalyzeMeshModel(MeshModel& model) {
	return 0;
}


int StrategySTEP::Export(std::string rootdir, Bitmap* pBitmap) {
	return 0;
}
