#pragma once

#include		<vector>
#include	<iostream>
#include	<numeric>
#define		_USE_MATH_DEFINES
#include	<math.h>

#include		"boost/graph/adjacency_list.hpp"
#include		"boost/graph/graph_utility.hpp"

namespace Strategy {

	class Vector3d {
	public:
		std::vector<double> _coordinate;

		Vector3d() {
			_coordinate.resize(3);
		}

		Vector3d(const Vector3d& obj) {
			this->_coordinate.clear();
			std::copy(obj._coordinate.begin(), obj._coordinate.end(), back_inserter(this->_coordinate));
		}

		~Vector3d() {

		}

		Vector3d& operator= (std::vector<double> vec) {
			Vector3d Vector3d;
			Vector3d._coordinate = vec;
			return Vector3d;
		}

		Vector3d operator+ (const Vector3d& rel) {
			Vector3d Vector3d;
			Vector3d._coordinate.resize(this->_coordinate.size());
			for (int i = 0; i < this->_coordinate.size(); i++) {
				Vector3d._coordinate[i] = this->_coordinate[i] + rel._coordinate[i];
			}
			return Vector3d;
		}

		Vector3d operator- (const Vector3d& rel) {
			Vector3d Vector3d;
			Vector3d._coordinate.resize(this->_coordinate.size());
			for (int i = 0; i < this->_coordinate.size(); i++) {
				Vector3d._coordinate[i] = this->_coordinate[i] - rel._coordinate[i];
			}
			return Vector3d;
		}

		Vector3d operator* (const double ratio) {
			Vector3d Vector3d;
			Vector3d._coordinate.resize(this->_coordinate.size());

			for (int i = 0; i < this->_coordinate.size(); i++) {
				Vector3d._coordinate[i] = this->_coordinate[i] * ratio;
			}

			return Vector3d;
		}

		double operator* (const Vector3d& ratio ) {
			double val = 0.0;

			for (int i = 0; i < this->_coordinate.size(); i++) {
				val += this->_coordinate[i] * ratio._coordinate[i];
			}

			return val;
		}

		Vector3d operator/ (const double ratio) {
			Vector3d Vector3d;
			Vector3d._coordinate.resize(this->_coordinate.size());

			for (int i = 0; i < this->_coordinate.size(); i++) {
				Vector3d._coordinate[i] = this->_coordinate[i] / ratio;
			}

			return Vector3d;
		}

		double operator[] (int i) {
			return this->_coordinate[i];
		}

		bool operator== (const Vector3d& obj) {
			for (int i = 0; i < this->_coordinate.size(); i++) {
				if (this->_coordinate[i] != obj._coordinate[i]) {
					return false;
				}
			}

			return true;
		}

		bool InRange(const Vector3d& p1, const Vector3d& p2, const double minerror = 0.0) const {
			for (int i = 0; i < this->_coordinate.size(); i++) {
				if (p1._coordinate[i] < p2._coordinate[i]) {
					if (!(p1._coordinate[i] <= (this->_coordinate[i] + minerror) && p2._coordinate[i] >= (this->_coordinate[i] - minerror))) {
						return false;
					}
				}
				else {
					if (!(p2._coordinate[i] <= (this->_coordinate[i] + minerror) && p1._coordinate[i] >= (this->_coordinate[i] - minerror))) {
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

		double AngleOnRThetaZ() {
			double angle = atan2(_coordinate[1], _coordinate[0]) ;
			//if (angle < 0) {
			//	angle += 2 * M_PI;
			//}

			return angle;
		}

		Vector3d CrossProduct(Vector3d& target) {
			Vector3d vec;
			vec._coordinate.resize(this->_coordinate.size());
			vec._coordinate[0] = this->_coordinate[1] * target._coordinate[2] - this->_coordinate[2] * target._coordinate[1];
			vec._coordinate[1] = this->_coordinate[2] * target._coordinate[0] - this->_coordinate[0] * target._coordinate[2];
			vec._coordinate[2] = this->_coordinate[0] * target._coordinate[1] - this->_coordinate[1] * target._coordinate[0];

			return vec;
		}

		double InnerProduct(Vector3d& target) {
			double res = 0.0;
			for (int i = 0; i < this->_coordinate.size(); i++) {
				res += this->_coordinate[i] * target._coordinate[i];
			}
			return res;
		}

		void Print() {
			for (int i = 0; i < this->_coordinate.size(); i++) {
				std::cout << this->_coordinate[i] << ",";
			}
			std::cout << std::endl;
		}

		void Format(std::string& format_text) {
			std::stringstream ss_str;
			ss_str << "[";
			for (int i = 0; i < this->_coordinate.size(); i++) {
				ss_str << std::fixed << this->_coordinate[i];

				if(i != this->_coordinate.size() - 1) {
					ss_str << ",";
				}
			}
			ss_str << "]";

			format_text = ss_str.str();
		}

		std::string ToString() {
			std::string str;
			Format(str);
			return str;
		}
	};

	class VertexElement {
	public:
		int _fileid;
		Vector3d _Point;
	};


	typedef enum class CurveEdge_Styles {
		UNDEFINED = 0,
		EDGE_LINE = 1,
		EDGE_CIRCLE = 2
	} ECURVEEDGE_STYLES;



	class EdgeCurveGeometry {
	public:
		EdgeCurveGeometry() {

		}
		EdgeCurveGeometry(const EdgeCurveGeometry& obj) {

		}
		virtual ~EdgeCurveGeometry() {

		}
	public:
		virtual ECURVEEDGE_STYLES GetType() {
			return CurveEdge_Styles::UNDEFINED;
		}
	};


	class EdgeElement {
	public:
		int _file_id;
		std::string _name;
		EdgeCurveGeometry* _geometry;	

	public:
		EdgeElement() {
			_geometry = NULL;
		}
		virtual ~EdgeElement() {
			//if (_geometry != NULL) {
				//delete _geometry;
			//}
		}

		bool operator == (const EdgeElement& element) const
		{
			return this->_geometry == element._geometry;
		}
	};


	class PropertyElement {
	public:
		std::string _name;
	};

	// details about boost library graph (Japanese)
	// https://boostjp.github.io/tips/graph.html
	typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, VertexElement, EdgeElement, PropertyElement> STEPMeshGraph;		// 無向グラフとしてデータ構造を定義


}
