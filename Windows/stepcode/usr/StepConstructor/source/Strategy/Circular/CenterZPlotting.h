#pragma once

#include	"../StrategyStep.h"
#include	"../MeshModel.h"

namespace Strategy {
	namespace Circular {
		
		class CenterZPlotting : public StrategySTEP {
		public:
			CenterZPlotting();
			CenterZPlotting(const StrategySTEP& obj);
			virtual ~CenterZPlotting();

			virtual int AnalyzeMeshModel(MeshModel& model);
			virtual int Export(std::string rootdir, Bitmap* pBitmap);
		};


	}

}