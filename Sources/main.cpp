#include <iostream>
#include <cmath>
#include "../Headers/Interface.h"


using namespace std;

int main()
{
	Interface I;
	I.Initialize();
	I.Print();
	I.PlayerMove('x');
	I.Print();
	I.PlayerMove('x');
	I.Print();
	I.PlayerMove('x');
	I.Print();
	I.PlayerMove('x');
	I.Print();
	cout << I.Check();


	return 0;
} //main
