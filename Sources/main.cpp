#include <iostream>
#include <cmath>
#include "../Headers/Interface.h"


using namespace std;

int main()
{
	Interface I;
	cout << "Gra w kolko i krzyzyk!" << endl;
	cout << "Wygrywa gracz ktoremu udalo sie ustawic 3 znaki w tej samej linii" << endl;
	cout << "Powodzenia!" << endl;
	I.Initialize();
	I.Game();

	return 0;
} //main
