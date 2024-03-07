#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

class Time
{
private:
	int gradus, min, sec;
public:
	void setGradus(int n) { gradus = n; };
	void setMin(int n) { min = n; };
	void setSec(int n) { sec = n; };

	void PrintGradus();
	void PrintMin();
	void PrintSec();

	float ToRadians();
};

