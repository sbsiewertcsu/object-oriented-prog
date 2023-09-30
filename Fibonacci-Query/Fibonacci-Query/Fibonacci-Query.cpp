// Fibonacci-Query.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int fibn=0, n=0, idx=0;
	ifstream fin;

	cout << "For what value of n would you like to look up the Fibonacci number? ";
    cin >> n;

	cout << "\nSearching C:\/temp\/fibonacci-precomputed.txt for n = " << n << "\n";

	fin.open("C:/temp/fibonacci-precomputed.txt");

	if (fin.fail())
	{
		cerr << "C:/temp/fibonacci-precomputed.txt file failed to open.\n";
		exit(-1);
	}

	while(idx <= n) 
	{
		// Evaluates to FALSE when no more data is left in file
		if(!(fin >> fibn))
		{
			cerr << "Value requested not found in file\n";
			exit(-1);
		}

		// Debug console output
		cout << "idx=" << idx << ", fn=" << fibn << "\n";

		idx++;
	}

	cout << "Fibonacci of " << n << " = " << fibn << "\n";

	fin.close();

	return 0;
}