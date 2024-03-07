#pragma once
#include <iostream>

using namespace std;

class Time
{
private:
	int hours, minutes;
public:
	Time() {
		hours = 0;
		minutes = 0;
	}
	Time(int h, int m) {
		hours = h;
		minutes = m;
	}

	Time operator - (const Time& t) {
		int m1 = this->hours * 60 + this->minutes;
		int m2 = t.hours * 60 + t.minutes;
		int time, h, m;
		//cout << m1 << " " << m2 << endl;
		if (m1 < m2) {
			time = 1440 - (m2 - m1);
			h = time / 60;
			m = time - h * 60;
		}
		else {
			time = m1 - m2;
			h = time / 60;
			m = time - h * 60;
		}
		return Time(h, m);
	};

	bool operator == (const Time& t) {
		return (this->hours == t.hours && this->minutes == t.minutes);
	}

	bool operator != (const Time& t) {
		return (this->hours != t.hours || this->minutes != t.minutes);
	}

	friend Time operator +(const Time& t, int m);

	void print() { cout << hours << ":" << minutes << endl; };

	~Time(){}
};


