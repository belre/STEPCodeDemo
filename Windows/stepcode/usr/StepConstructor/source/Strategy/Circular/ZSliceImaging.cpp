

#include	<iostream>
#include	<numeric>
#define		_USE_MATH_DEFINES
#include	<math.h>

#include	<Windows.h>
#include	<stdio.h>
#include	<gdiplus.h>
using namespace Gdiplus;

#include	"ZSliceImaging.h"
#include	"../ConcreteCurveEdgeGeometry.h"
#include	"../Numeric/Solver.h"

#include	"strconv.h"

using namespace Strategy::Circular;
using namespace Strategy::Numeric;

ZSliceImaging::ZSliceImaging() {

}

ZSliceImaging::ZSliceImaging(const StrategySTEP& obj) {

}

ZSliceImaging::~ZSliceImaging() {

}

int ZSliceImaging::AnalyzeMeshModel(MeshModel& model) {
	double base_z_begin = -0.1;
	double base_z_end = 5;

	double resolution_x = 0.254 / 12;			// mm
	double resolution_y = 0.254 / 12;			// mm
	double width = 80;						// mm
	double height = 80;						// mm
	int imgwidth = (int)(width / resolution_x + 0.5);
	int imgheight = (int)(height / resolution_y + 0.5);

	// Initialize GDI+
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Create Bitmap Object and refer graphics object
	Bitmap* pBitmap = new Bitmap(imgwidth, imgheight);
	Graphics* grf = Graphics::FromImage(pBitmap);

	grf->FillRectangle(new Gdiplus::SolidBrush(Color::Black), 0, 0, imgwidth, imgheight);

	auto iter_edge = model._graph.m_edges.begin();
	for (; iter_edge != model._graph.m_edges.end(); iter_edge++) {
		// Extract Vertex
		Vector3d vertexPoint_source = model._graph[iter_edge->m_source]._Point;
		Vector3d vertexPoint_target = model._graph[iter_edge->m_target]._Point;

		if (!(vertexPoint_source[2] >= base_z_begin && vertexPoint_source[2] <= base_z_end)) {
			continue;
		}

		if (!(vertexPoint_target[2] >= base_z_begin && vertexPoint_target[2] <= base_z_end)) {
			continue;
		}

		float source_pos_x = (vertexPoint_source[0] / resolution_x) + imgwidth / 2;
		float source_pos_y = (vertexPoint_source[1] / resolution_y) + imgheight / 2;
		float target_pos_x = (vertexPoint_target[0] / resolution_x) + imgwidth / 2;
		float target_pos_y = (vertexPoint_target[1] / resolution_y) + imgheight / 2;

		// Paint XY Vector3d
		CircleEdgeGeometry* circle = dynamic_cast<CircleEdgeGeometry*>((iter_edge->m_property._geometry));

		if (circle != NULL) {
			//if (circle->_radius < 10) {
#if 0
				grf->DrawEllipse(new Gdiplus::Pen(new Gdiplus::SolidBrush(Color::Black)),
					(float)((circle->_center0[0] - circle->_radius) / resolution_x) + imgwidth / 2,
					(float)((circle->_center0[1] - circle->_radius) / resolution_y) + imgheight / 2,
					(float)((2 * circle->_radius) / resolution_x),
					(float)((2 * circle->_radius) / resolution_y));
#endif
				Vector3d circle_orbit_source = vertexPoint_source - circle->_center0;
				Vector3d circle_orbit_target = vertexPoint_target - circle->_center0;

				double diffangle = circle_orbit_target.AngleOnRThetaZ() - circle_orbit_source.AngleOnRThetaZ();
				if (diffangle > M_PI) {
					diffangle -= 2 * M_PI;
				} else if (diffangle < -M_PI) {
					diffangle += 2 * M_PI;
				}
				//diffangle /= 2;

				grf->DrawArc(new Gdiplus::Pen(new Gdiplus::SolidBrush(Color::White)),
					(float)((circle->_center0[0] - circle->_radius) / resolution_x) + imgwidth / 2,
					(float)((circle->_center0[1] - circle->_radius) / resolution_y) + imgheight / 2,
					(float)((2 * circle->_radius) / resolution_x),
					(float)((2 * circle->_radius) / resolution_y),
					circle_orbit_source.AngleOnRThetaZ() * 180 / M_PI, diffangle * 180 / M_PI);
					//circle_orbit_source.AngleOnRThetaZ() * 180 / M_PI,
					//diffangle * 180 / M_PI);
			//}
		} else {
			grf->DrawLine(new Gdiplus::Pen(new Gdiplus::SolidBrush(Color::White)), source_pos_x, source_pos_y, target_pos_x, target_pos_y);
		}
	}

	CLSID bmpClsId;
	CLSIDFromString( L"{557CF400-1A04-11D3-9A73-0000F81EF32E}", &bmpClsId);

	wstring wpath = sjis_to_wide(_rootpath);

	wstringstream ss_wexportpath;
	ss_wexportpath << wpath << L"\\SliceZ_Imaging.bmp";


	Status status = pBitmap->Save(ss_wexportpath.str().c_str(), &bmpClsId);

	delete pBitmap;
	GdiplusShutdown(gdiplusToken);



	return 0;
}

int ZSliceImaging::Export(std::string rootdir, Bitmap* pBitmap) {
	return 0;
}


