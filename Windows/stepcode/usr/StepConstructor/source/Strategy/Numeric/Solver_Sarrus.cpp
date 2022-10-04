
#include	"Solver.h"


using namespace Strategy::Numeric;

double Solver::Sarrus3(std::vector<double> matrix) {
	if (matrix.size() != 9) {
		return NAN;
	}

	double val = 0;
	val += matrix[0 * 3 + 0] * matrix[1 * 3 + 1] * matrix[2 * 3 + 2];
	val += matrix[1 * 3 + 0] * matrix[2 * 3 + 1] * matrix[0 * 3 + 2];
	val += matrix[2 * 3 + 0] * matrix[0 * 3 + 1] * matrix[1 * 3 + 2];
	val -= matrix[0 * 3 + 2] * matrix[1 * 3 + 1] * matrix[2 * 3 + 0];
	val -= matrix[1 * 3 + 2] * matrix[2 * 3 + 1] * matrix[0 * 3 + 0];
	val -= matrix[2 * 3 + 2] * matrix[0 * 3 + 1] * matrix[1 * 3 + 0];

	return val;
}

