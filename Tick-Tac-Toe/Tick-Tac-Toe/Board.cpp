#pragma once
#include "Board.h"
#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <ctime>
#define LOG(x) std::cout << "ERROR:" << x << "\n";
#define ENDOFBOARD 8

Board::Board ()
{
	std::srand(std::time(nullptr));
	state = rand() % 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}

}

bool Board::checkVictoryCross(int row, int column) 
{
	//check horizontal
	for (int i = 0; i < 3; i++) {
		if (board[row - 1][i] == cross) {
			if (i == 2)
				return true;
		}
		else {
			break;
		}
	}
	//check vertical
	for (int i = 0; i < 3; i++) {
		if (board[i][column - 1] == cross) {
			if (i == 2)
				return true;
		}
		else {
			break;
		}
	}

	//check diagonal
	if (board[0][0] == cross && board[1][1] == cross && board[2][2] == cross)
		return true;
	else if (board[0][2] == cross && board[1][1] == cross && board[2][0] == cross)
		return true;


	return false;
}

bool Board::checkVictoryCircle(int row, int column)
{

	//check horizontal
	for (int i = 0; i < 3; i++) {
		if (board[row - 1][i] == circle) {
			if (i == 2)
				return true;
		}
		else {
			break;
		}
	}
	//check vertical
	for (int i = 0; i < 3; i++) {
		if (board[i][column - 1] == circle) {
			if (i == 2)
				return true;
		}
		else {
			break;
		}
	}
	
	//check diagonal
	if (board[0][0] == circle && board [1][1] == circle && board[2][2] == circle)
		return true;
	else if (board[0][2] == circle && board[1][1] == circle && board[2][0] == circle)
		return true;


	return false;
}

void Board::print()
{
	std::cout << "[" << board[0][0] << "][" << board[0][1] << "][" << board[0][2] << "]\n";
	std::cout << "[" << board[1][0] << "][" << board[1][1] << "][" << board[1][2] << "]\n";
	std::cout << "[" << board[2][0] << "][" << board[2][1] << "][" << board[2][2] << "]\n";
}

void Board::set(int row, int column)
{
	int settingSymbol;
	if (state == 0) {
		settingSymbol = circle;
	}
	else if (state == 1) {
		settingSymbol = cross;
	}
	else {
		LOG("NOT 0 OR 1")
	}

	board[row - 1][column - 1] = settingSymbol;
	this->print();
	
	if (settingSymbol == circle && this->checkVictoryCircle(row, column)) {
		std::cout << "CIRCLE WINS!!!";
		victoryAchieved = true;
	}
	else if (settingSymbol == cross && this->checkVictoryCross(row, column)) {
		std::cout << "CROSS WIN!!!";
		victoryAchieved = true;
		
	}

	(state == 0) ? state = 1 : state = 0;
}

void Board::readInput() 
{
	int convertedColumnInput;
	int input;

	std::cout << "Please make your move\n";
	std::cin >> input;

	switch (input % 3) {
		case 1:
			convertedColumnInput = 1;
			break;
		case 2:
			convertedColumnInput = 2;
			break;
		case 0:
			convertedColumnInput = 3;
			break;
		default:
			LOG("Error in converted convertedInput into convertedColumnInput")
	}

	this->set(std::ceil(input / 3.00) , convertedColumnInput);

}