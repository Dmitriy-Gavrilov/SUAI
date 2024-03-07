#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

using namespace std;

template <typename T>
class TestClass
{
private:
	int m1 = 0, m2 = 10;
	static const int len_arr = 10;
	vector<T> arr;

public:
	TestClass() {	
		for (int i = 0; i < len_arr; i++) {
			arr.push_back(rand() % m2);
		}
	}

	void operator()(int a, int b){
		for (auto& x: arr) {
			x = x * a + b;
		}
	}

	void print() {
		for (int i = 0; i < len_arr; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	T summ() {
		T s = accumulate(arr.begin(), arr.end(), 0);
		return s;
	}

	void change_array() {
		transform(arr.begin(), arr.end(), arr.begin(), [](T a) {if (a > 20) { a = 10; }; return a;  });
	}
};

