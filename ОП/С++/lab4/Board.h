#pragma once
#include <string>
#include <map>

using namespace std;

class Board
{
protected:
	static const int n = 8;

	string chess_board[n][n];

	char dict[n]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	map <char, int> numbers{
		{'1', 1},  {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}
	};

public:
	Board();

	char NumToStr(int num);

	int StrToNum(char s);

	//void Filling();

};