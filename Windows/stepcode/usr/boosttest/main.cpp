
#include		"main.h"
#include		<iostream>
#include		<sstream>

#include		<vector>
#include		"boost/graph/adjacency_list.hpp"
#include		"boost/graph/graph_utility.hpp"


class Point {
public:
	std::vector<double> _coordinate;

	Point& operator= (std::vector<double> vec) {
		Point point;
		point._coordinate = vec;
		return point;
	}

	Point operator+ (const Point& rel) {
		Point point;
		point._coordinate.resize(this->_coordinate.size());
		for (int i = 0; i < this->_coordinate.size(); i++) {
			point._coordinate[i] = this->_coordinate[i] + rel._coordinate[i];
		}
		return point;
	}

	Point operator- (const Point& rel) {
		Point point;
		point._coordinate.resize(this->_coordinate.size());
		for (int i = 0; i < this->_coordinate.size(); i++) {
			point._coordinate[i] = this->_coordinate[i] - rel._coordinate[i];
		}
		return point;
	}

	Point operator* (const double ratio) {
		Point point;
		point._coordinate.resize(this->_coordinate.size());

		for (int i = 0; i < this->_coordinate.size(); i++) {
			point._coordinate[i] = this->_coordinate[i] * ratio;
		}

		return point;
	}


	Point operator/ (const double ratio) {
		Point point;
		point._coordinate.resize(this->_coordinate.size());

		for (int i = 0; i < this->_coordinate.size(); i++) {
			point._coordinate[i] = this->_coordinate[i] / ratio;
		}

		return point;
	}


	bool InRange(const Point &p1, const Point &p2) {
		for (int i = 0; i < this->_coordinate.size(); i++) {
			if (p1._coordinate[i] < p2._coordinate[i]) {
				if (!(p1._coordinate[i] <= this->_coordinate[i] && p2._coordinate[i] >= this->_coordinate[i])) {
					return false;
				}
			} else {
				if (!(p2._coordinate[i] <= this->_coordinate[i] && p1._coordinate[i] >= this->_coordinate[i])) {
					return false;
				}
			}
		}

		return true;
	}

	double Length() {
		double len = 0;
		for (int i = 0; i < this->_coordinate.size(); i++) {
			len += this->_coordinate[i] * this->_coordinate[i];
		}

		return sqrt(len);
	}

};

class VertexElement {
public:
	int _fileid;
	Point _point;

};

class EdgeType {
public:
	int _type;			// 0 : spline, 1 : line, 2 : circle
	double _radius;
	std::vector<Point> _connected_points;
};

class EdgeElement {
public:
	std::string _name;

};


// details about boost library graph (Japanese)
// https://boostjp.github.io/tips/graph.html
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, VertexElement, EdgeElement> StepGraph;		// 無向グラフとしてデータ構造を定義


int main(int argv, char** argc)
{
	StepGraph graph;

	int width = 4;
	int height = 4;
	std::vector<double> normal_vector_1 = { 1.0, 1.0, 0 };
	std::vector<double> normal_vector_2 = { 0, 0, 1.0 };


	std::vector<StepGraph::vertex_descriptor> vertex_list;

	int num = 1;
	// Set Vertex
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			StepGraph::vertex_descriptor v = add_vertex(graph);
			graph[v]._fileid = num++;

			graph[v]._point._coordinate.resize(3);
			for (int k = 0; k < normal_vector_1.size(); k++) {
				graph[v]._point._coordinate[k] = normal_vector_1[k] * i + normal_vector_2[k] * j;
			}
		}
	}

	// Set Edge of cross-type
	for (int i = 0; i < graph.m_vertices.size(); i++) {
		for (int j = 0; j < graph.m_vertices.size(); j++) {
			if (i < j) {
				Point vertpi = graph.m_vertices[i].m_property._point;
				Point vertpj = graph.m_vertices[j].m_property._point;

				Point diff = vertpi - vertpj;
				bool isconnect = true;
				for (int k = 0; k < normal_vector_1.size(); k++) {
					double th = abs(normal_vector_1[k]) > abs(normal_vector_2[k]) ? abs(normal_vector_1[k]) : abs(normal_vector_2[k]);

					if (abs(diff._coordinate[k]) > th || abs(diff._coordinate[k]) > th) {
						isconnect = false;
					}
				}

				if (isconnect) {
					StepGraph::edge_descriptor e12;
					bool inserted = false;
					boost::tie(e12, inserted) = add_edge(i, j, graph);

					std::stringstream ss;
					ss << "#" << graph.m_vertices[i].m_property._fileid << "-#" << graph.m_vertices[j].m_property._fileid;
					graph[e12]._name = ss.str();
				}
			}
		}
	}

	std::vector<double> unit_normal_vector = { 0, 1, 0 }; // { 1 / sqrt(2), 1 / sqrt(2), 0 };

	Point cross_point0 = Point();
	cross_point0._coordinate = { 1, 1, 1.5 };

	Point cross_point_tar = Point();
	double length = 20;
	cross_point_tar._coordinate = { 0, 0 ,0 };
	for (int i = 0; i < cross_point_tar._coordinate.size(); i++) {
		cross_point_tar._coordinate[i] = cross_point0._coordinate[i] + length * unit_normal_vector[i];
	}


	double error_val = 1E-10;



	// search edge
	auto edge_range = edges(graph);
	for (auto first = edge_range.first, last = edge_range.second; first != last; first++) {
		Point source_point = graph[first->m_source]._point;
		Point target_point = graph[first->m_target]._point;
		

		Point diff1 = cross_point_tar - cross_point0;
		Point diff2 = source_point - cross_point0;
		Point diff3 = target_point - cross_point0;
		Point diffq = target_point - source_point;

		/// Saras Official
		/// 
		double diag_val =
			diff1._coordinate[0] * diff2._coordinate[1] * diff3._coordinate[2] +
			diff1._coordinate[1] * diff2._coordinate[2] * diff3._coordinate[0] +
			diff1._coordinate[2] * diff2._coordinate[0] * diff3._coordinate[1] -
			diff1._coordinate[2] * diff2._coordinate[1] * diff3._coordinate[0] -
			diff1._coordinate[1] * diff2._coordinate[0] * diff3._coordinate[2] -
			diff1._coordinate[0] * diff2._coordinate[2] * diff3._coordinate[1];

		if (abs(diag_val) < error_val) {


			// 暫定として、２本のベクトルから出てくるパラメータ変数s,tの係数が線形独立かどうかを判定し、
			// そうであれば、直線の方程式を使用して、交点を演算する
			std::vector<int> linearindependent_index;
			std::vector<int> lineardependent_index;
			{
				for (int i = 0; i < 3; i++) {
					for (int j = i + 1; j < 3; j++) {
						double diag2d = - diff1._coordinate[i] * diffq._coordinate[j] + diff1._coordinate[j] * diffq._coordinate[j];

						if (abs(diag2d) > error_val) {
							linearindependent_index.push_back(i);
							linearindependent_index.push_back(j);
						} else {
							lineardependent_index.push_back(i);
							lineardependent_index.push_back(j);
						}
					}
				}
			}

			// 線形従属の解が、方程式として不可能解でないかどうかを調べる
			// ※省略
			for (int i = 0; i < lineardependent_index.size(); i += 2) {

			}

			// 線形独立の解を参照する
			if (linearindependent_index.size() >= 2) {
				// パラメータs, tを逆行列から演算
				double diag2d_2 = - diff1._coordinate[linearindependent_index[0]] * diffq._coordinate[linearindependent_index[1]] + diff1._coordinate[linearindependent_index[1]] * diffq._coordinate[linearindependent_index[0]];

				double a11 = diff1._coordinate[linearindependent_index[0]];
				double a12 = -diffq._coordinate[linearindependent_index[0]];
				double a21 = diff1._coordinate[linearindependent_index[1]];
				double a22 = -diffq._coordinate[linearindependent_index[1]];

				double param_s = (a22 * (diff2._coordinate[linearindependent_index[0]]) - a12 * (diff2._coordinate[linearindependent_index[1]])) / diag2d_2;
				double param_t = (- a21 *(diff2._coordinate[linearindependent_index[0]]) + a11 * (diff2._coordinate[linearindependent_index[1]])) / diag2d_2;

				Point crosspoint = diff1 * param_s + cross_point0;
				Point crosspoint2 = diffq * param_t + source_point;
				// crosspointはcross_point0, cross_point_tar, target_point, source_pointの指定されたベクトル範囲に含まれている必要がある
				
				if (crosspoint.InRange(cross_point0, cross_point_tar) && crosspoint.InRange(source_point, target_point)) {
					std::cout << "#" << graph[first->m_source]._fileid << ",#" << graph[first->m_target]._fileid << std::endl;
					std::cout << "p0:" << cross_point0._coordinate[0] << "," << cross_point0._coordinate[1] << "," << cross_point0._coordinate[2] << std::endl;
					std::cout << "p1:" << cross_point_tar._coordinate[0] << "," << cross_point_tar._coordinate[1] << "," << cross_point_tar._coordinate[2] << std::endl;
					std::cout << "q0:" << source_point._coordinate[0] << "," << source_point._coordinate[1] << "," << source_point._coordinate[2] << std::endl;
					std::cout << "q1:" << target_point._coordinate[0] << "," << target_point._coordinate[1] << "," << target_point._coordinate[2] << std::endl;


					std::cout << diff1._coordinate[linearindependent_index[0]] << "s + " << -diffq._coordinate[linearindependent_index[0]] << "t = " << diff2._coordinate[linearindependent_index[0]] << std::endl;
					std::cout << diff1._coordinate[linearindependent_index[1]] << "s + " << -diffq._coordinate[linearindependent_index[1]] << "t = " << diff2._coordinate[linearindependent_index[1]] << std::endl;
					std::cout << "s=" << param_s << std::endl;
					std::cout << "t=" << param_t << std::endl;

					std::cout << "x=" << crosspoint._coordinate[0] << std::endl;
					std::cout << "y=" << crosspoint._coordinate[1] << std::endl;
					std::cout << "z=" << crosspoint._coordinate[2] << std::endl;
					std::cout << "x=" << crosspoint2._coordinate[0] << std::endl;
					std::cout << "y=" << crosspoint2._coordinate[1] << std::endl;
					std::cout << "z=" << crosspoint2._coordinate[2] << std::endl;
					std::cout << "Inrange[p]=" << crosspoint.InRange(cross_point0, cross_point_tar) << std::endl;
					std::cout << "Inrange[q]=" << crosspoint.InRange(source_point, target_point) << std::endl;

				}


			}




		}

	}




	boost::print_graph(graph);
#if 0
	StepGraph::vertex_descriptor v1 = add_vertex(graph);
	StepGraph::vertex_descriptor v2 = add_vertex(graph);

	graph[v1]._fileid = 1;
	graph[v1]._point = { 1.0 ,2.0, 3.0 };

	graph[v2]._fileid = 2;
	graph[v2]._point = { 3.0, 2.0, 9.0 };

	StepGraph::edge_descriptor e12;
	bool inserted = false;
	boost::tie(e12, inserted) = add_edge(v1, v2, graph);
	graph[e12]._name = "#1-#2";
	
	EdgeElement* ptr = reinterpret_cast<EdgeElement*>( e12.get_property());
	std::cout << ptr->_name << std::endl;
	
	auto edge_range = edges(graph);
	for (auto first = edge_range.first, last = edge_range.second; first != last; ++first) {
		std::cout << graph[first->m_source]._fileid << std::endl;
		std::cout << graph[first->m_target]._fileid << std::endl;
	}




	boost::print_graph(graph);
#endif
	return 0;
}
