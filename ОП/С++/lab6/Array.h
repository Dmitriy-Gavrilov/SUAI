#pragma once
#include <iostream>
#include "ArrayException.h"

using namespace std;


class Array
{
private:
	static const int size = 12;
	int arr[size]{};
public:
	Array();

	void print_array();

	int product();

	int find_first_zero(int arr[], int len);

	int find_last_zero(int arr[], int len, int ind1);

	int summ_between_zeros();

	void transform();
};

