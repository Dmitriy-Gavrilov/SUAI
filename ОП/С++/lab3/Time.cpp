#include "Time.h"

Time operator +(const Time& t, int m2) {
	int m1 = t.hours * 60 + t.minutes;
	int time = (m1 + m2) / 60;
	int h = time % 24;
	int m = m1 + m2 - time * 60;
	return Time(h, m);
}