#include "Board.h"


Board::Board() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			chess_board[i][j] = "empty";
		}
	}
}
char Board::NumToStr(int num) {
	for (int i = 0; i < n; i++) {
		if (i + 1 == num) {
			return dict[i];
		}
	}
}

int Board::StrToNum(char s) {
	for (int i = 0; i < n; i++) {
		if (dict[i] == s) {
			return i + 1;
		}
	}
}

//void Board::Filling() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			chess_board[i][j] = "empty";
//		}
//	}
//}
