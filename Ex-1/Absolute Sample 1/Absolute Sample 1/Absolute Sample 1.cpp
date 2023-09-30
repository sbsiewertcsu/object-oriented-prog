// Absolute Sample 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int numberOfLanguages;

	cout << "Hello reader.\n"
		<< "Welcome to C++.\n";

	cout << "How many programming languages have you used?";
	cin >> numberOfLanguages;

	if(numberOfLanguages < 1)
	{
		cout << "Read the preface - you may want a simpler book.\n";
	}
	else
	{
		cout << "Enjoy the book.\n";
	}

	return 0;
}

