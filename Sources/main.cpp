#include <iostream>
#include <cmath>
#include "../Headers/Interface.h"


using namespace std;

int main()
{
	Interface I;
	cout << "Gra w kolko i krzyzyk!" << endl;
	I.Initialize();
	I.Game();

	return 0;
} //main
