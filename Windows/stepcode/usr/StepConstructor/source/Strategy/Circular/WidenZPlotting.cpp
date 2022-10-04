
#include	"WidenZPlotting.h"
#include	"../Numeric/Solver.h"
#include	"../ConcreteCurveEdgeGeometry.h"

#include	<iostream>
#include	<numeric>
#define		_USE_MATH_DEFINES
#include	<math.h>

#include	<chrono>

#include	<Windows.h>
#include	<stdio.h>
#include	<gdiplus.h>
using namespace Gdiplus;

#include	<strconv.h>


using namespace Strategy::Circular;
using namespace Strategy::Numeric;

WidenZPlotting::WidenZPlotting() {

}

WidenZPlotting::WidenZPlotting(const StrategySTEP& obj) {

}

WidenZPlotting::~WidenZPlotting() {

}

int WidenZPlotting::AnalyzeMeshModel(MeshModel& model) {

#if 0
	double base_z = 2.5;
	double base_R = 28;
	double X0 = 45;
	double Y0 = 40;
	double Theta0_deg = 60;
	double Theta0 = Theta0_deg * M_PI / 180;
	double Rl = -0.1;
	double Ru = 5;
	double Ll = -0.1;
	double Lu = 5;
#else

	auto func_double_settingval = [] (string key, boost::property_tree::ptree &jsonsetting, double default_val=0.0) {
		double val = default_val;
		if (boost::optional<double> optional = jsonsetting.get_optional<double>(key)) {
			val = optional.get();
		}
		return val;
	};

	//double base_z = 2.5;
	double lower_z = func_double_settingval("ZPlotting.lower_z", _jsonsetting, 0.0);
	double upper_z = func_double_settingval("ZPlotting.upper_z", _jsonsetting, 4.3);
	double resolution_z = func_double_settingval("ZPlotting.resolution_z", _jsonsetting, 0.1);
	double phase_diff = (2 * M_PI) / func_double_settingval("ZPlotting.rotation_frequency", _jsonsetting, 256.0);

	double base_R = func_double_settingval("ZPlotting.base_r", _jsonsetting, 13.0);
	double X0 = func_double_settingval("ZPlotting.camera_X0", _jsonsetting, 45.0);
	double Y0 = func_double_settingval("ZPlotting.camera_Y0", _jsonsetting, 45.0);
	double Theta0_deg = func_double_settingval("ZPlotting.camera_Theta0_deg", _jsonsetting, 45.0);;
	double Theta0 = Theta0_deg * M_PI / 180;
	double Rl = func_double_settingval("ZPlotting.surfacerange_Rl", _jsonsetting, -0.1);
	double Ru = func_double_settingval("ZPlotting.surfacerange_Ru", _jsonsetting, 5.0);
	double Ll = func_double_settingval("ZPlotting.surfacerange_Ll", _jsonsetting, -0.1);
	double Lu = func_double_settingval("ZPlotting.surfacerange_Lu", _jsonsetting, 5.0);
#endif

	_width = (upper_z - lower_z) / resolution_z + 1;
	_height = 2 * M_PI / phase_diff;
	_widenZ_data.resize(_width * _height, 2.5);


	// Define equation of a plane which is along with cylindrical surface
	double linear_tilt_coef = tan(Theta0);
	double linear_intercept_coef = Y0 - tan(Theta0) * X0;


	// Calculate the crossPoint Q between cylinder and line
	double X_another, X_solve, Y_solve = 0.0;
	auto pow2 = [](double val) { return val * val;  };
	//if (Theta0_deg >= 0 && Theta0_deg <= 90) {
		double c1 = pow2(linear_tilt_coef);
		double c3 = pow2(linear_intercept_coef);
		double c2 = pow2(linear_intercept_coef) - pow2(base_R);
		double D = c1 * c3 - (1 + c1) * c2;
		X_another = (-linear_tilt_coef * linear_intercept_coef - sqrt(D)) / (1 + c1);
		X_solve = c2 / (X_another * (1 + c1));
		Y_solve = linear_tilt_coef * X_solve + (Y0 - linear_tilt_coef * X0);
	//}

	auto rotate_Point = [](double phase, Vector3d org) {
		Vector3d res;
		res._coordinate.resize(3);
		res._coordinate[0] = cos(phase) * org._coordinate[0] - sin(phase) * org._coordinate[1];
		res._coordinate[1] = sin(phase) * org._coordinate[0] + cos(phase) * org._coordinate[1];
		res._coordinate[2] = org._coordinate[2];

		return res;
	};



	bool isTriggered = false;
	boost::list_edge<size_t, EdgeElement> before_edge;
	double phase_limit = 2 * M_PI;

	for( int l = 0 ; l < _height; l ++ ) {
		double phase = l * phase_diff;
		// Define normal vector of the plane
		Vector3d normal_2d_t1_plane;
		normal_2d_t1_plane._coordinate = { cos(Theta0), sin(Theta0), 0 };
		normal_2d_t1_plane = rotate_Point(-phase, normal_2d_t1_plane);
		Vector3d normal_2d_t2_plane;
		normal_2d_t2_plane._coordinate = { 0, 0, 1 };			//{ -sin(Theta0), cos(Theta0), 0 };
		normal_2d_t2_plane = rotate_Point(-phase, normal_2d_t2_plane);
		Vector3d originated_Point_plane;
		originated_Point_plane._coordinate = { X_solve, Y_solve, 0 };
		originated_Point_plane = rotate_Point(-phase, originated_Point_plane);



		// iterate the crossPoint of model
		auto edges = model._graph.m_edges;
		auto graph = model._graph;


		//end = chrono::system_clock::now();
		//std::cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0) << "[ms]" << std::endl;
		//start = chrono::system_clock::now();

		vector<Vector3d> candidates;
		for (auto iter_edge = edges.begin(); iter_edge != edges.end(); iter_edge++) {
			auto edge = *iter_edge;

			// Normalize roi linear vector
			Vector3d parallel_roi_linear = (graph[edge.m_target]._Point - graph[edge.m_source]._Point);
			parallel_roi_linear = parallel_roi_linear / parallel_roi_linear.Length();

			// Substract 2 originated Vector3d
			Vector3d diff_originated_Point = originated_Point_plane - graph[edge.m_source]._Point;

			vector<double> matrix_directional = {
				parallel_roi_linear[0], -normal_2d_t1_plane[0], -normal_2d_t2_plane[0],
				parallel_roi_linear[1], -normal_2d_t1_plane[1], -normal_2d_t2_plane[1],
				parallel_roi_linear[2], -normal_2d_t1_plane[2], -normal_2d_t2_plane[2],
			};
			vector<double> matrix_line_param = {
				diff_originated_Point[0], -normal_2d_t1_plane[0], -normal_2d_t2_plane[0],
				diff_originated_Point[1], -normal_2d_t1_plane[1], -normal_2d_t2_plane[1],
				diff_originated_Point[2], -normal_2d_t1_plane[2], -normal_2d_t2_plane[2],
			};
			vector<double> matrix_plane_param1 = {
				parallel_roi_linear[0], diff_originated_Point[0], -normal_2d_t2_plane[0],
				parallel_roi_linear[1], diff_originated_Point[1], -normal_2d_t2_plane[1],
				parallel_roi_linear[2], diff_originated_Point[2], -normal_2d_t2_plane[2],
			};
			vector<double> matrix_plane_param2 = {
				parallel_roi_linear[0], -normal_2d_t1_plane[0], diff_originated_Point[0],
				parallel_roi_linear[1], -normal_2d_t1_plane[1], diff_originated_Point[1],
				parallel_roi_linear[2], -normal_2d_t1_plane[2], diff_originated_Point[2],
			};


			double diag_directional = Solver::Sarrus3(matrix_directional);

			if (abs(diag_directional) >= model.MIN_ERROR) {
				double sli = Solver::Sarrus3(matrix_line_param) / diag_directional;
				double sp1 = Solver::Sarrus3(matrix_plane_param1) / diag_directional;
				double sp2 = Solver::Sarrus3(matrix_plane_param2) / diag_directional;

				Vector3d source = graph[edge.m_source]._Point;
				Vector3d target = graph[edge.m_target]._Point;
				Vector3d crossPoint = parallel_roi_linear * sli + graph[edge.m_source]._Point;

				bool isvalid = true;


				if (crossPoint.InRange(source, target, model.MIN_ERROR)) {
					// crossPoint is calculated as linear combination, so correct by the curve model
					CircleEdgeGeometry* circle = dynamic_cast<CircleEdgeGeometry*>(edge.get_property()._geometry);

					if (circle != NULL) {
						Vector3d normal_vector = circle->_normal_vector;
						Vector3d first_ref_vector = Vector3d(crossPoint);//circle->_first_ref_vector;
						first_ref_vector._coordinate[2] = 0;
						first_ref_vector = first_ref_vector / first_ref_vector.Length();
						Vector3d second_ref_vector = normal_vector.CrossProduct(first_ref_vector); //circle->_second_ref_vector;
						Vector3d center0 = circle->_center0;
						center0._coordinate[2] = 0.0;
						Vector3d crosspoint_Tmp = Vector3d(crossPoint) - center0;
						crosspoint_Tmp._coordinate[2] = 0.0;

						auto comb_t1t2 = first_ref_vector - second_ref_vector * first_ref_vector.InnerProduct(second_ref_vector);
						vector<double> param = {
							comb_t1t2.InnerProduct(comb_t1t2),
							comb_t1t2.InnerProduct(crosspoint_Tmp),
							crosspoint_Tmp.InnerProduct(crosspoint_Tmp) - circle->_radius * circle->_radius
						};
						double D_param = param[1] * param[1] - param[0] * param[2];
						if (D_param <= 0) {
							isvalid = false;
						}
						else {
							double s1a, s1b, s2a, s2b = 0.0;
							if (param[1] >= 0) {
								s1a = (-param[1] - sqrt(D_param)) / (param[0]);
								s2a = -s1a * first_ref_vector.InnerProduct(second_ref_vector);
								s1b = param[2] / (param[0] * s1a);
								s2b = -s1b * first_ref_vector.InnerProduct(second_ref_vector);
							}
							else {
								s1b = (-param[1] + sqrt(D_param)) / (param[0]);
								s2b = -s1b * first_ref_vector.InnerProduct(second_ref_vector);
								s1a = param[2] / (param[0] * s1b);
								s2a = -s1b * first_ref_vector.InnerProduct(second_ref_vector);
							}


							Vector3d pca, pcb;
							pca = first_ref_vector * s1a + second_ref_vector * s2a + crosspoint_Tmp + center0;
							pcb = first_ref_vector * s1b + second_ref_vector * s2b + crosspoint_Tmp + center0;

							Vector3d diff_pca, diff_pcb, diff_tar, diff_source;
							diff_pca = pca - center0;
							diff_pcb = pcb - center0;
							diff_tar = target - center0;
							diff_tar._coordinate[2] = 0.0;
							diff_source = source - center0;
							diff_source._coordinate[2] = 0.0;

							double diffanglea = diff_pca.AngleOnRThetaZ() - diff_source.AngleOnRThetaZ();

#if 1
							if (diffanglea > M_PI) {
								diffanglea -= 2 * M_PI;
							}
							else if (diffanglea < -M_PI) {
								diffanglea += 2 * M_PI;
							}
#endif

							double diffangleb = diff_pcb.AngleOnRThetaZ() - diff_source.AngleOnRThetaZ();

#if 1
							if (diffangleb > M_PI) {
								diffangleb -= 2 * M_PI;
							}
							else if (diffangleb < -M_PI) {
								diffangleb += 2 * M_PI;
							}
#endif

							double diffangletar = diff_tar.AngleOnRThetaZ() - diff_source.AngleOnRThetaZ();
#if 1
							if (diffangletar > M_PI) {
								diffangletar -= 2 * M_PI;
							}
							else if (diffangletar < -M_PI) {
								diffangletar += 2 * M_PI;
							}
#endif

#if 1
							if (diffangletar >= 0) {
								if (diffanglea <= diffangletar && diffanglea >= 0 && diffangleb <= diffangletar && diffangleb >= 0) {
									crossPoint = diffanglea < diffangleb ? pca : pcb;
								}
								else if (diffanglea <= diffangletar && diffanglea >= 0) {
									crossPoint = pca;
								}
								else if (diffangleb <= diffangletar && diffangleb >= 0) {
									crossPoint = pcb;
								}
								else {
									isvalid = false;
								}
							}
							else {
								if (-diffanglea <= -diffangletar && diffanglea < 0 && -diffangleb <= -diffangletar && diffangleb < 0) {
									crossPoint = -diffanglea < -diffangleb ? pca : pcb;
								}
								else if (-diffanglea <= -diffangletar && diffanglea < 0) {
									crossPoint = pca;
								}
								else if (-diffangleb <= -diffangletar && diffangleb < 0) {
									crossPoint = pcb;
								}
								else {
									isvalid = false;
								}
							}
							crossPoint._coordinate[2] += circle->_center0[2];
#endif							
						}							
					}

					Vector3d diff = (crossPoint - originated_Point_plane);
					double innerproduct_1 = diff * normal_2d_t1_plane;
					double innerproduct_2 = diff * normal_2d_t2_plane;

					if (innerproduct_1 >= Rl && innerproduct_1 <= Ru && innerproduct_2 >= Ll && innerproduct_2 <= Lu && isvalid) {
						candidates.push_back(crossPoint);
					}
				}

#if 0
				Vector3d diff = (crossPoint - originated_Point_plane);
				double innerproduct_1 = diff * normal_2d_t1_plane;
				double innerproduct_2 = diff * normal_2d_t2_plane;
				if (innerproduct_1 >= Rl && innerproduct_1 <= Ru && innerproduct_2 >= Ll && innerproduct_2 <= Lu) {



					//std::cout << "#" << graph[edge.m_source]._fileid << ",";
					//graph[edge.m_source]._Point.Print();
					//std::cout << "#" << graph[edge.m_target]._fileid << ",";
					//graph[edge.m_target]._Point.Print();
					//std::cout << "X=" << crossPoint[0] << ",Y=" << crossPoint[1] << ",Z=" << crossPoint[2] << std::endl;

					//candidates.push_back(edge);
					candidates.push_back(crossPoint);

				}
#endif
			}
		}


		int l_phase = phase / phase_diff;
		for (int k = 0; k < _width; k++) {
			double base_z = resolution_z * k;

			Vector3d lower_z_crossPoint;
			lower_z_crossPoint._coordinate = { 0, 0, -DBL_MAX };
			Vector3d upper_z_crossPoint;
			upper_z_crossPoint._coordinate = { 0, 0, DBL_MAX };
			int count_crossPoint = 0;;
			if (candidates.size() >= 2) {

				if (!isTriggered) {
					//before_edge = candidates[0];
				}

				// Select the nearest Vector3d to base_z
				for (int i = 0; i < candidates.size(); i++) {
					double z = candidates[i]._coordinate[2] - base_z;

					if (z >= 0) {
						if (abs(upper_z_crossPoint._coordinate[2] - base_z) > abs(z)) {
							upper_z_crossPoint = candidates[i];
							count_crossPoint++;
						}
					}
					else {
						if (abs(lower_z_crossPoint._coordinate[2] - base_z) > abs(z)) {
							lower_z_crossPoint = candidates[i];
							count_crossPoint++;
						}
					}

				}

				isTriggered = true;
			}

			if (isTriggered && count_crossPoint >= 2) {
				double alllen = abs(upper_z_crossPoint[2] - lower_z_crossPoint[2]);
				double source_len = abs(base_z - upper_z_crossPoint[2]);
				double target_len = abs(base_z - lower_z_crossPoint[2]);

				Vector3d interpolation;
				interpolation = upper_z_crossPoint * (target_len / alllen) + lower_z_crossPoint * (source_len / alllen);

				double distance1 = (interpolation - originated_Point_plane) * normal_2d_t1_plane; //sqrt(interpolation[0] * interpolation[0] + interpolation[1] * interpolation[1]);

				double valid_phase = phase >= 2 * M_PI ? phase - 2 * M_PI : phase;

				_widenZ_data[k + l * _width] = distance1;

				//std::cout << valid_phase << "," << k << "," << l_phase << "," << distance1 << std::endl;
			}
			else {
				_widenZ_data[k + l * _width] = 0;
				//std::cout << phase << "," << "!!" << std::endl;
#if 0
				if (phase >= 2 * M_PI) {
					phase_limit = 2 * M_PI;
				}
				else {
					phase_limit += phase_diff;
				}
#endif
			}

		}

	}


	// Export Image 
	{
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		Bitmap* pBitmap = new Bitmap(_width, _height);
		this->Export(_rootpath, pBitmap);

		delete pBitmap;
		GdiplusShutdown(gdiplusToken);
	}

	return 0;
}

int WidenZPlotting::Export(std::string rootdir, Bitmap* pBitmap) {


	auto func_double_settingval = [](string key, boost::property_tree::ptree& jsonsetting, double default_val = 0.0) {
		double val = default_val;
		if (boost::optional<double> optional = jsonsetting.get_optional<double>(key)) {
			val = optional.get();
		}
		return val;
	};

	double range_r_min = func_double_settingval("ZPlotting.measure_range_lower_r", _jsonsetting, 0.0);
	double range_r_max = func_double_settingval("ZPlotting.measure_range_upper_r", _jsonsetting, 6.0);
	
	BitmapData pBitmapdata;
	pBitmap->LockBits(new Gdiplus::Rect(0, 0, _width, _height), ImageLockMode::ImageLockModeWrite, PixelFormat8bppIndexed, &pBitmapdata);
	
	int bitCount = Gdiplus::GetPixelFormatSize(PixelFormat8bppIndexed);
	int stride = (_width * bitCount + 31) / 32 * 4;

	byte* bdata = reinterpret_cast<byte*>( pBitmapdata.Scan0);

	for (int j = 0; j < _height; j++) {
		for (int i = 0; i < _width; i++) {
			double val = _widenZ_data[i + j * _width];
			if (val < range_r_min) {
				val = 0.0;
			} else if (val >= range_r_max) {
				val = range_r_max;
			}

			byte b = (byte)(255 * (val - range_r_min) / (range_r_max - range_r_min));
			bdata[i + j * stride] = b;
		}
	}

	Gdiplus::ColorPalette* palette = new Gdiplus::ColorPalette[256];
	palette->Flags = (UINT)Gdiplus::PaletteFlags::PaletteFlagsGrayScale;
	palette->Count = 256;
	for (int i = 0; i < 256; i++) {
		palette->Entries[i] = Color::MakeARGB(0, (BYTE)i, (BYTE)i, (BYTE)i);
	}
	pBitmap->SetPalette(palette);
	pBitmap->UnlockBits(&pBitmapdata);

	CLSID bmpClsId;
	CLSIDFromString( L"{557CF400-1A04-11D3-9A73-0000F81EF32E}", &bmpClsId);

	wstring wpath = sjis_to_wide(rootdir);

	wstringstream ss_wexportpath;
	ss_wexportpath << wpath << L"\\ThetaZ_Imaging.bmp";

	Status status = pBitmap->Save(ss_wexportpath.str().c_str() , &bmpClsId);

	return 0;
}

