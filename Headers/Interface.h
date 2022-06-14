#pragma once
#include<vector> 
#include<string> 
#include<iostream> 


#define WIN 1;
#define NO_VALUE 0;
#define TIE -1;
#define END -2;

class AI
{
public:
	int currentScore;
	char AIplayer, HumanPlayer;
	int Xindex, Yindex;
public:
	AI() = default;
	AI(int _score) : currentScore(_score) {}
};


class Interface {
private:
	AI Move;
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

	char GetValue(int x, int y) { return board[x][y];}

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

	void PlayerMove(char _sign) {

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
	};


	void Game() 
    {

		Move.AIplayer = 'o';
		Move.HumanPlayer = 'x';
		SetValues(Move.Xindex, Move.Yindex, Move.AIplayer);
		Print();
	};

    int Check() 
    {

        for (int i = 0; i < size; i++)
        {
            int counter = 1;
            for (int j = 0; j < size - 1; j++) 
            {
                if ((GetValue(i, j) == GetValue(i, j + 1)) && (GetValue(i, j) != ' ')) 
                {
                    counter++;
                    if (counter == winStreak) 
                    {
                        return WIN;
                    }
                }
                else
                {
                    counter = 1;
                }
            }
        }


        //w pionie
        for (int i = 0; i < size; i++) 
        {
            int counter = 1;
            for (int j = 0; j < size - 1; j++) 
            {
                if ((GetValue(j, i) == GetValue(j + 1, i)) && (GetValue(j, i) != ' ')) 
                {
                    counter++;
                    if (counter == winStreak) 
                    {
                        return WIN;
                    }
                }
                else 
                {
                    counter = 1;
                }
            }
        }

        //po ukosie z lewej do prawej
        int counter = 1;
        for (int i = 0; i < size - winStreak - 1; i++) 
        {

            if ((GetValue(i, i) == GetValue(i + 1, i + 1)) && (GetValue(i, i) != ' ')) 
            {
                counter++;
                if (counter == winStreak) 
                {
                    return WIN;
                }
            }
            else 
            {
                counter = 1;
            }
        }

        //po ukosie z lewej do prawej

        for (int i = 1; i < size - winStreak + 1; i++) 
        {
            int counter = 1;
            for (int k = 0; k < (size - i - 1); k++) 
            {
                if ((GetValue(k, i + k) == GetValue(k + 1, i + k + 1)) && (GetValue(k, i + k) != ' ')) 
                {
                    counter++;
                    if (counter == winStreak) 
                    {
                        return WIN;
                    }
                }
                else 
                {
                    counter = 1;
                }
            }
        }


        // po przekatnej od prawej do lewej
        for (int i = 0; i < size + 1; i++) 
        {
            int counter = 1;
            for (int k = 0; k < (size - i - 1); k++) 
            {
                if ((GetValue(size - 1 - k, i + k) == GetValue(size - 1 - (k + 1), i + k + 1)) &&
                    (GetValue(size - 1 - k, i + k) != ' ')) 
                {
                    counter++;
                    if (counter == size) 
                    {
                        return WIN;
                    }
                }
                else
                {
                    counter = 1;
                }
            }
        }


        int counter2 = 0;
        for ( int i = 0; i < size; i++) 
        {
            for ( int j = 0;j < size; j++) 
            {
                if (GetValue(i, j) == ' ') 
                {
                    counter2++;
                }
            }
        }

        for (size_t i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                if (board[i][j] == ' ') return NO_VALUE;
            }
        }

        if (counter2 == 0) 
        {
            return END;
        }
        return TIE;
    }

}; //CLASS