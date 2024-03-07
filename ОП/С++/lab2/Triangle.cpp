#include "Triangle.h"

float Triangle::Angles(string angle) {
	float cosa = (pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c);
	float cosb = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b);
	float cosc = (pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * c * b);

	float anglea = acos(cosa) * 180.0 / M_PI;
	float angleb = acos(cosb) * 180.0 / M_PI;
	float anglec = acos(cosc) * 180.0 / M_PI;

	if (angle == "anglea") {
		return anglea;
	}
	else if (angle == "angleb") {
		return angleb;
	}
	else {
		return anglec;
	}
};