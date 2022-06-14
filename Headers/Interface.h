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
    int size = 3;
    char cell = ' ';
	std::string* board; 
    int winStreak;

public:


	void Print()
	{
		board = new std::string[size];
		for (int i = 0; i < size; i++)	for (int j = 0; j < size; j++) board[i][j] = (char)' ';

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
};