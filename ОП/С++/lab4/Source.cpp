#include "Composition.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");

	Composition comp;
	//comp.Filling();

	comp.PrintBoard();

	comp.AddFigure("Queen", "D5");
	comp.AddFigure("King", "A8");
	comp.PrintBoard();
	cout << endl;
	comp.DeleteFigure("A8");
	comp.AddFigure("King", "D5");
	comp.PrintBoard();


	return 0;
}