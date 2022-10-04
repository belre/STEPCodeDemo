
#include	"CenterZPlotting.h"
#include	"../Numeric/Solver.h"
#include	"../ConcreteCurveEdgeGeometry.h"

#include	<iostream>
#include	<numeric>
#define		_USE_MATH_DEFINES
#include	<math.h>

#include	<chrono>

using namespace Strategy::Circular;
using namespace Strategy::Numeric;

CenterZPlotting::CenterZPlotting() {

}

CenterZPlotting::CenterZPlotting(const StrategySTEP& obj) {

}

CenterZPlotting::~CenterZPlotting() {

}

int CenterZPlotting::AnalyzeMeshModel(MeshModel& model) {

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
	//double base_z = 2.5;
	double base_z = 3.5; //2.145;
	double base_R = 13;
	double X0 = 45;
	double Y0 = 45;
	double Theta0_deg = 45;
	double Theta0 = Theta0_deg * M_PI / 180;
	double Rl = -2;
	double Ru = 5;
	double Ll = -0.1;
	double Lu = 5;
#endif

	
	// Define equation of a plane which is along with cylindrical surface
	double linear_tilt_coef = tan(Theta0);
	double linear_intercept_coef = Y0 - tan(Theta0) * X0;
	

	// Calculate the crossPoint Q between cylinder and line
	double X_another, X_solve, Y_solve = 0.0;
	auto pow2 = [](double val) { return val * val;  };
	if (Theta0_deg > 0 && Theta0_deg < 90) {		
		double c1 = pow2(linear_tilt_coef);
		double c3 = pow2(linear_intercept_coef);
		double c2 = pow2(linear_intercept_coef) - pow2(base_R);
		double D = c1 * c3 - (1 + c1) * c2;
		X_another = (- linear_tilt_coef * linear_intercept_coef - sqrt(D)) / (1+c1);
		X_solve = c2 / (X_another * (1 + c1));
		Y_solve = linear_tilt_coef * X_solve + (Y0 - linear_tilt_coef * X0);
	}

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
	double phase_diff = M_PI / 1024;
	for (double phase = 0; phase < phase_limit; phase += phase_diff) {
		// Define normal vector of the plane
		Vector3d normal_2d_t1_plane;
		normal_2d_t1_plane._coordinate = { cos(Theta0 ), sin(Theta0), 0 };
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

			Vector3d source = graph[edge.m_source]._Point;
			Vector3d target = graph[edge.m_target]._Point;

			// Parallel roi linear vector
			Vector3d parallel_roi_linear = rotate_Point(0, (graph[edge.m_target]._Point - graph[edge.m_source]._Point));
			parallel_roi_linear = parallel_roi_linear / parallel_roi_linear.Length();

			// Substract 2 originated Vector3d
			Vector3d diff_originated_Point = originated_Point_plane - source;

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


				Vector3d crossPoint = parallel_roi_linear * sli + source;
				bool isvalid = true;

				if (crossPoint.InRange(source, target, model.MIN_ERROR)) {
					// crossPoint is calculated as linear combination, so correct by the curve model
					CircleEdgeGeometry* circle = dynamic_cast<CircleEdgeGeometry*>(edge.get_property()._geometry);

#if 1
					if (circle != NULL) {
						Vector3d normal_vector = circle->_normal_vector;
						Vector3d first_ref_vector = Vector3d(crossPoint) ;//circle->_first_ref_vector;
						first_ref_vector._coordinate[2] = 0;
						first_ref_vector = first_ref_vector / first_ref_vector.Length();
						Vector3d second_ref_vector = normal_vector.CrossProduct(first_ref_vector); //circle->_second_ref_vector;
						Vector3d center0 = circle->_center0;
						center0._coordinate[2] = 0.0;
						Vector3d crosspoint_Tmp = Vector3d(crossPoint) - center0;
						crosspoint_Tmp._coordinate[2] = 0.0;

						auto comb_t1t2 = first_ref_vector - second_ref_vector * first_ref_vector.InnerProduct(second_ref_vector) ;
						vector<double> param = {  
							comb_t1t2.InnerProduct(comb_t1t2), 
							comb_t1t2.InnerProduct(crosspoint_Tmp),
							crosspoint_Tmp.InnerProduct(crosspoint_Tmp) - circle->_radius * circle->_radius 
						};
						double D_param = param[1] * param[1] - param[0] * param[2];
						if (D_param <= 0) {
							isvalid = false;
						} else {
							double s1a, s1b, s2a, s2b = 0.0;
							if (param[1] >= 0) {
								s1a = (-param[1] - sqrt(D_param)) / (param[0]);
								s2a = -s1a * first_ref_vector.InnerProduct(second_ref_vector);
								s1b = param[2] / (param[0] * s1a);
								s2b = -s1b * first_ref_vector.InnerProduct(second_ref_vector);
							} else {
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
								if (diffanglea <= diffangletar && diffanglea >= 0 && diffangleb <= diffangletar && diffangleb >= 0){
									crossPoint = diffanglea < diffangleb ? pca : pcb;
								} else if (diffanglea <= diffangletar && diffanglea >= 0) {
									crossPoint = pca;
								} else if (diffangleb <= diffangletar && diffangleb >= 0) {
									crossPoint = pcb;
								} else {
									isvalid = false;
								}
							} else {
								if (-diffanglea <= -diffangletar && diffanglea < 0 && -diffangleb <= -diffangletar && diffangleb < 0) {
									crossPoint = -diffanglea < -diffangleb ? pca : pcb;
								} else if (-diffanglea <= -diffangletar && diffanglea < 0) {
									crossPoint = pca;
								} else if (-diffangleb <= -diffangletar && diffangleb < 0) {
									crossPoint = pcb;
								} else {
									isvalid = false;
								}
							}
							crossPoint._coordinate[2] += circle->_center0[2];
#endif
							
						}							
					}

#endif
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
				} else {
					if (abs(lower_z_crossPoint._coordinate[2] - base_z) > abs(z)) {
						lower_z_crossPoint = candidates[i];
						count_crossPoint++;
					}
				}



#if 0
				double distance1_z_candidate = abs(graph[candidates[i].m_source]._Point[2] - base_z);
				double distance2_z_candidate = abs(graph[candidates[i].m_target]._Point[2] - base_z);
				double distance_z_candidate = distance1_z_candidate < distance2_z_candidate ? distance1_z_candidate : distance2_z_candidate;

				double distance1_z_before = abs(graph[before_edge.m_source]._Point[2] - base_z);
				double distance2_z_before = abs(graph[before_edge.m_target]._Point[2] - base_z);
				double distance_z_before = distance1_z_before < distance2_z_before ? distance1_z_before : distance2_z_before;

				if (distance_z_candidate < distance_min) {
					//before_edge = candidates[i];
					distance_min = distance_z_candidate;
				}
#endif
			}

			isTriggered = true;
		}


		if (count_crossPoint < 2) {
			std::cout << phase << "," << "!!" << std::endl;
		}

		if (isTriggered && count_crossPoint >= 2) {
			double alllen = abs(upper_z_crossPoint[2] - lower_z_crossPoint[2]);
			double source_len = abs(base_z - upper_z_crossPoint[2]);
			double target_len = abs(base_z - lower_z_crossPoint[2]);

			Vector3d interpolation;
			interpolation = upper_z_crossPoint * (target_len / alllen) + lower_z_crossPoint * (source_len / alllen);

			double distance1 = (interpolation - originated_Point_plane) * normal_2d_t1_plane; //sqrt(interpolation[0] * interpolation[0] + interpolation[1] * interpolation[1]);

			double valid_phase = phase >= 2 * M_PI ? phase - 2 * M_PI : phase;
			
			//distance1 = sqrt(upper_z_crossPoint[0] * upper_z_crossPoint[0] + upper_z_crossPoint[1] * upper_z_crossPoint[1]);
			//Vector3d med = (upper_z_crossPoint + lower_z_crossPoint) / 2;
			//double distance1 = sqrt(med[0] * med[0] + med[1] * med[1]);

			std::cout << valid_phase << "," << distance1 << std::endl;
		} else {
			if (phase >= 2 * M_PI) {
				phase_limit = 2 * M_PI;
			} else {
				phase_limit += phase_diff;
			}
		}

	}

	return 0;
}

int CenterZPlotting::Export(std::string rootdir, Bitmap* pBitmap) {
	return 0;
}

