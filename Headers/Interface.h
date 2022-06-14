#pragma once
#include<vector> 
#include<string> 
#include<iostream> 

class AI
{
private:
	int currentScore;
	char AIplayer;
	int Xindex, Yindex;
public:
	AI() = default;
	AI(int _score) : currentScore(_score) {}
};


class Interface {
private:

	int size;
	char cell = ' ';
	std::string* board;
	int winStreak;

public:
	void Initialize()
	{
		std::cout << "Podaj rozmiar" << std::endl;
		std::cin >> size;
		board = new std::string[size];
		for (int i = 0; i < size; i++)	for (int j = 0; j < size; j++) board[i][j] = (char)' ';
	}

	int GetSize() const { return size; };

	void Print()
	{
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << "_";
			for (int j = 0; j < size - 1; j++)
			{
				std::cout << board[i][j] << "_|_";
			}
			std::cout << board[i][size - 1] << "_" << std::endl;
		}
		std::cout << " ";
		for (int j = 0; j < size - 1; j++)
		{
			std::cout << board[size - 1][j] << " | ";
		}
		std::cout << board[size - 1][size - 1] << std::endl;// << " ";
	}

	void SetValues(int row, int column, char _cell) {
		cell = _cell;
		board[row][column] = cell;
	}

	void Move(char _sign) {

		int row, column;
		do
		{
			std::cin >> row;
			std::cin >> column;
			if (!std::cin.good())
			{
				std::cout << "Spruboj ponownie" << std::endl;
				std::cin.clear();
				//cin.unget();
				std::cin.ignore(100, ' ');
				//cout << "bad" << endl;
				row = 1000;  //zamkniecie petli
			}
		} while (row >= size || row < 0 || column >= size || column < 0 || board[row][column] != ' ');
		SetValues(row, column, _sign);
	}

}; //CLASS