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
	void Initialize()
	{
		std::cout << "Podaj rozmiar planszy" << std::endl;
		std::cin >> size;
		board = new std::string[size];
		for (int i = 0; i < size; i++)	for (int j = 0; j < size; j++) board[i][j] = (char)' ';
	}

    //drukowanie planszy
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
    //Metody dostepu
    int GetSize() const { return size; };
    char GetValue(int x, int y) { return board[x][y]; }

   //Metody zmiany atrybutow
	void SetValues(int row, int column, char _cell) {
		cell = _cell;
		board[row][column] = cell;
	}

    //Wybor komorki (przez gracza)
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
				std::cin.ignore(100, ' ');
				row = 1000;  //zamkniecie petli
			}
		} while (row >= size || row < 0 || column >= size || column < 0 || board[row][column] != ' ');
		SetValues(row, column, _sign);
	};

    //Metoda rozpoczynajaca gre
	void Game() 
    {
		Move.AIplayer = 'o';
		Move.HumanPlayer = 'x';
		Print();
        //sprawdzenie wygranej
        while (Check() != 1) {
            std::cout << "Wykonaj ruch" << std::endl;
            PlayerMove(Move.HumanPlayer);  //zaczyna gracz
            Print();
            if (Check() == WIN)  //sprawdzenie ruch wygrywajacy
            {
                std::cout << "Koniec gry. Wygral gracz " << std::endl;
            }
            else if (Check() == END)  //sprawdzenie ruch konczacy rozgrywke
            {
                std::cout << "Koniec miejsca na planszy, gra skonczona." << std::endl;
            }
            std::cout << "Prosze czekac ruch wykonuje komputer " << std::endl;
            MinMax(Move.AIplayer); //ruch komputera
            SetValues(Move.Xindex, Move.Yindex, Move.AIplayer);
            Print();
            if (Check() == WIN)  //sprawdzenie ruch wygrywajacy
            {
                std::cout << "Koniec gry. Wygral komputer " << std::endl;
            }
            else if (Check() == END)  //sprawdzenie ruch konczacy rozgrywke
            {
                std::cout << "Koniec miejsca na planszy. Gra zostala zakonczona." << std::endl;
            }
        }
	};

    //Metoda sprawdzajaca stan gry (wygrana, przegrana, remis)
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
        for (int i = 0; i < size - 1; i++) 
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
        for (int i = 1; i < size + 1; i++) 
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


    AI MinMax(char player) {

        //wywolanie metody rekurencyjnie, tworzy wektor ruchow
        if (Check() == WIN && (player == Move.AIplayer))  return { 10 }; //komputer wygrywa
        else if ((Check() == WIN) && (player == Move.HumanPlayer)) return { -10 }; //czlowiek wygrywa
        else if ((Check() == TIE) || (Check() == END))  return { 0 };  //remis

        std::vector<AI> moves;

        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                if (GetValue(i, j) == ' ') 
                {
                    Move.Xindex = i;
                    Move.Yindex = j;
                    cell = player;
                    SetValues(i, j, player);
                    //sprawdzamy jaka bedzie wartosc score dla przeciwnika
                    Move.currentScore = MinMax(player == Move.AIplayer ? Move.HumanPlayer : Move.AIplayer).currentScore; 
                    moves.push_back(Move);
                    SetValues(i, j, ' '); //wracamy do poczatku
                }
            }
        }

        //wybor najlepszego ruchu
        int bestMove = 0;
        if (player == Move.AIplayer) {
            int bestScore = INT32_MIN; //minimalna wartosc aby dazyl do wygranej
            for (size_t i = 0; i < moves.size(); i++) 
            {
                if (moves[i].currentScore > bestScore) 
                { 
                    bestMove = i;//ustawienie najlepszego ruchu 
                    bestScore = moves[i].currentScore; //ustalenie maksymalnej wartosci
                }
            }
        }
        else { //dla przeciwnika ustala minimalne wartosci
            int bestScore = INT32_MAX; //maksymalna wartosc aby dazyl do minimalnej straty
            for (size_t i = 0; i < moves.size(); i++) {
                if (moves[i].currentScore < bestScore) { 
                    bestMove = i;//ustawienie najlepszego ruchu dla komputera najgorszy dla przeciwnika
                    bestScore = moves[i].currentScore; //ustalenie minimalnej wartosci
                }
            }
        }
        return moves[bestMove];
    }
}; //CLASS