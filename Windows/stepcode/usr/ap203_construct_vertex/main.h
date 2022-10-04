// ap203min.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include		<iostream>
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

	bool operator== (const Point& obj) {
		for (int i = 0; i < this->_coordinate.size(); i++) {
			if (this->_coordinate[i] != obj._coordinate[i]) {
				return false;
			}
		}

		return true;
	}

	bool InRange(const Point& p1, const Point& p2, const double minerror = 0.0) const {
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








