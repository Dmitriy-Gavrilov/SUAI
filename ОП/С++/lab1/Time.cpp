#include "Time.h"

void Time::PrintGradus() { cout << gradus << endl; }

void Time::PrintMin() { cout << min << endl; }

void Time::PrintSec() { cout << sec << endl; }

float Time::ToRadians() {
	return (gradus + min / 60 + sec / 3600) * M_PI / 180;
}
