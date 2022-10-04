#pragma once

#include		"GraphDefinitionForBoost.h"


namespace Strategy {


	class LineEdgeGeometry : public EdgeCurveGeometry {
	public:
		LineEdgeGeometry() {

		}
		LineEdgeGeometry(const LineEdgeGeometry& obj) {

		}
		virtual ~LineEdgeGeometry() {

		}
	
	public:
		virtual ECURVEEDGE_STYLES GetType() {
			return ECURVEEDGE_STYLES::EDGE_LINE;
		}
	};


	class CircleEdgeGeometry: public EdgeCurveGeometry {
	public:
		double		_radius;
		Vector3d		_center0;
		Vector3d		_normal_vector;
		Vector3d		_first_ref_vector;
		Vector3d		_second_ref_vector;

	public:
		CircleEdgeGeometry() {

		}
		CircleEdgeGeometry(const CircleEdgeGeometry& obj) {

		}
		virtual ~CircleEdgeGeometry() {

		}
	public:
		virtual ECURVEEDGE_STYLES GetType() {
			return ECURVEEDGE_STYLES::EDGE_CIRCLE;
		}

	};


}