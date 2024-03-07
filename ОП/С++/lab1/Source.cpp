#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

int correct_input(string s) {
	int n;
	cout << s << endl;
	cin >> n;
	while (n < 0 || !cin.good() || cin.get() != '\n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введено некорректное значение переменной. Повторите ввод." << endl;
		cout << s << endl;
		cin >> n;
	}
	return n;
}


int main() {
	setlocale(LC_ALL, "Ru");
	Time ugol;

	ugol.setGradus(correct_input("Введите значение угла в градусах (целое число)"));
	ugol.setMin(correct_input("Введите значение угла в угловых минутах (целое число)"));
	ugol.setSec(correct_input("Введите значение угла в угловых секундах (целое число)"));

	cout << "Исходные значения:" << endl;
	ugol.PrintGradus();
	ugol.PrintMin();
	ugol.PrintSec();

	cout << "Значение угла в радианах: " << ugol.ToRadians() << endl;

	return 0;
};