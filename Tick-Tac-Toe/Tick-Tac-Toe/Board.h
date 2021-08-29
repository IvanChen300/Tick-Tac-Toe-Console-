#pragma once
#include <vector>

class Board
{
	public:
		std::vector<bool> slotsFilled;
		std::vector<char> slots;
		char board[3][3];
		bool victoryAchieved;

	private:
		const static char cross = 'X';
		const static char circle = 'O';
		int state;

	public:
		Board();

		bool checkVictoryCross(int row, int column);
		bool checkVictoryCircle(int row, int column);
		void print();
		void set(int row, int column);
		void readInput();
};

