#pragma once
#include "Board.h"
#include <iostream>

using namespace std;

class Composition : public Board
{
public:
	Composition() :Board() {};

	/*void Filling() {
		Board::Filling();
	}*/

	void AddFigure(string figure, string position);

	void DeleteFigure(string position);

	void PrintBoard();

};