#pragma once

#include	"../StrategyStep.h"
#include	"../MeshModel.h"


#include	<Windows.h>
#include	<stdio.h>
#include	<gdiplus.h>
using namespace Gdiplus;

namespace Strategy {
	namespace Circular {

		class ZSliceImaging : public StrategySTEP {
		public:
			ZSliceImaging();
			ZSliceImaging(const StrategySTEP& obj);
			virtual ~ZSliceImaging();

			virtual int AnalyzeMeshModel(MeshModel& model);
			virtual int Export(std::string rootdir, Bitmap* pBitmap);
		};


	}

}