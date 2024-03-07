#include "Array.h"

Array::Array() {
	cin.exceptions(cin.failbit);
	cout << "������� �������� �������" << endl;
	for (int i = 0; i < size; i++) {
		try
		{
			cout << i + 1 << "-� �������: ";
			cin >> arr[i];
		}
		catch (exception& ex)
		{
			cout << "������: " << ex.what() << endl;
			cin.clear();
			cin.ignore(10, '\n');
			i--;
		}
	}
}

void Array::print_array() {
	for (int i = 0; i <= size; i++) {
		try
		{
			if (i < size) {
				cout << arr[i] << " ";
			}
			else {
				throw exception("����� �� ������� �������");
			}
		}
		catch (exception& ex)
		{
			cout << endl << "������: " << ex.what() << endl;
		}
	}
	cout << endl;
}

int Array::product() {
	int	p = 1;
	for (int i = 0; i < size; i += 2) {
		p *= arr[i];
	}
	return p;
}

int Array::find_first_zero(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == 0) {
			return i;
		}
	}
	return len;
}

int Array::find_last_zero(int arr[], int len, int ind1) {
	for (int i = len - 1; i >= 0; i--) {
		if (arr[i] == 0 && i != ind1) {
			return i;
		}
	}
	return len;
}

int Array::summ_between_zeros() {
	int ind1 = find_first_zero(arr, size);
	int ind2 = find_last_zero(arr, size, ind1);
	int summ = 0;

	if (ind1 == size || ind2 == size) {
		throw ArrayException("������. ���������� ������� ��������� ������ 2", 1);
	}

	for (int i = ind1; i <= ind2; i++) {
		summ += arr[i];
	}
	return summ;
}

void Array::transform() {
	int step = size - 1;
	bool f = true;

	while (f || step > 1) {
		int i = 0;
		f = false;
		while (i + step < size) {
			if (arr[i] < arr[i + step]) {
				int t = arr[i];
				arr[i] = arr[i + step];
				arr[i + step] = t;
				f = true;
			}
			i += 1;
		}
		step = int(step / 1.247);
	}
}
