#pragma once
#include<vector> 
#include<string> 
#include<iostream> 


int const WIN = 1;
int const NO_VALUE = 0;
int const TIE = -1;
int const END = -2;

class AI
{
public:
	int currentScore;
	char AIplayer, HumanPlayer;
	int Xindex, Yindex;
public:
	AI() = default;
    AI(int _score) : currentScore(_score), AIplayer(' '), HumanPlayer(' '), Xindex(0), Yindex(0) {};
};


class Interface {
private:
	AI Move;
	int size;
	char cell = ' ';
	std::string* board;
	int winStreak = 3;

public:
    //inicializowanie planszy o podanym wymiarze
    void Initialize();

    //drukowanie planszy
    void Print();
    //Metody dostepu
    int GetSize() const { return size; };
    char GetValue(int x, int y) { return board[x][y]; };

   //Metody zmiany atrybutow
    void SetValues(int row, int column, char _cell) { cell = _cell; board[row][column] = cell; };

    //Wybor komorki (przez gracza)
    void PlayerMove(char _sign);

    //Metoda rozpoczynajaca gre
	void Game();

    //Metoda sprawdzajaca stan gry (wygrana, przegrana, remis)
    int Check();

    //metoda MinMax
    AI MinMax(char player);
   
}; //CLASS