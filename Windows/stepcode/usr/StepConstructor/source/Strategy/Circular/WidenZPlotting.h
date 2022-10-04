#pragma once

#include	"../StrategyStep.h"
#include	"../MeshModel.h"

#include	<vector>

namespace Strategy {
	namespace Circular {

		class WidenZPlotting : public StrategySTEP {
		public:
			std::vector<double> _widenZ_data;
			int _width;
			int	_height;
		public:
			WidenZPlotting();
			WidenZPlotting(const StrategySTEP& obj);
			virtual ~WidenZPlotting();

			virtual int AnalyzeMeshModel(MeshModel& model);
			virtual int Export(std::string rootdir, Bitmap* pBitmap);
		};


	}

}