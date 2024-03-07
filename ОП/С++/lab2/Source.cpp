#include "Triangle.h"
#include <iostream>

using namespace std;

int main(){
	setlocale(LC_ALL, "Ru");

	Triangle tr1;

	Triangle tr2(3, 4, 5);

	Triangle tr3(tr2);

	cout << "Углы треугольника 1:" << endl;
	cout << tr1.Angles("anglea") << " " << tr1.Angles("angleb") << " " << tr1.Angles("anglec") << endl;

	cout << "Углы треугольника 2:" << endl;
	cout << tr2.Angles("anglea") << " " << tr2.Angles("angleb") << " " << tr2.Angles("anglec") << endl;

	cout << "Углы треугольника 3:" << endl;
	cout << tr3.Angles("anglea") << " " << tr3.Angles("angleb") << " " << tr3.Angles("anglec") << endl;

	return 0;
}