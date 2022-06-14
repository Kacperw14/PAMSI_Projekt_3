#include <iostream>
#include <cmath>
#include "../Headers/Interface.h"


using namespace std;

int main()
{
	Interface I;
	I.Initialize();
	I.Print();
	I.SetValues(1,1,'x');
	I.Print();

	return 0;
} //main
