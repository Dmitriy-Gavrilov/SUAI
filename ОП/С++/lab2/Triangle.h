#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Triangle
{
private:
	float a, b, c;
public:
	Triangle() {
		a = 3;
		b = 4;
		c = 5;
	}

	Triangle(float avalue, float bvalue, float cvalue) {
		a = avalue;
		b = bvalue;
		c = cvalue;
	}

	Triangle(const Triangle &t){
		a = t.a;
		b = t.b;
		c = t.c;
	}
	
	~Triangle() {};

	float Angles(string angle);
};

