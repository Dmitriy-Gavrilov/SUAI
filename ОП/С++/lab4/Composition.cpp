#include "Composition.h"

//Composition::Composition() :Board();

void Composition::AddFigure(string figure, string position) {
	int ind1 = StrToNum(position[0]) - 1;
	int ind2 = numbers[position[1]] - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == ind1 && j == ind2) {
				if (chess_board[ind1][ind2] == "empty") {
					chess_board[ind1][ind2] = figure;
				}
				else {
					cout << "Эта позиция уже занята" << endl;
				}
				return;
			}
		}
	}
}

void Composition::DeleteFigure(string position) {
	int ind1 = StrToNum(position[0]) - 1;
	int ind2 = numbers[position[1]] - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == ind1 && j == ind2) {
				chess_board[ind1][ind2] = "empty";
				return;
			}
		}
	}
}

void Composition::PrintBoard() {
	cout << "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t" << endl;
	for (int i = 0; i < n; i++) {
		cout << dict[i] << "\t";
		for (int j = 0; j < n; j++) {
			cout << chess_board[i][j] << "\t";
		}
		cout << endl;
	}
}


