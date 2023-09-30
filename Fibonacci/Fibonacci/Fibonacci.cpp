// Fibonacci.cpp : Defines the entry point for the console application.
//

// This stdafx.h is pre-processed in the Visual Studio environment to make builds quicker
#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
	// f(0)=0, f(1)=1, f(2)=f(1)+f(0), idx=1 to start
	unsigned int fn=1, fn_minus_1=1, fn_minus_2=0;
	unsigned int idx=1;
	unsigned int n=20;

	ofstream fout;

	// pre-computed value output file
	fout.open("C:/temp/fibonacci-precomputed.txt");

	cout << "Fibonacci Computer\n";
	cout << "For what value of n would you like to compute Fibonacci(n)? ";
	cin >> n; 

	cout << "\nComputing for n = " << n << "\n";

	if(n == 0) 
	{
		// By defintion of the sequence
		cout << "fibonacci of 0 = 0\n";

		// Fibonacci pre-computed file output
		fout << "0\n";
	}
	else if(n == 1)
	{
		// By definition of the sequence
		cout << "fibonacci of 1 = 1\n";

		// Fibonacci pre-computed file output
		fout << "1\n";
	}
	else
	{
		// Fibonacci pre-computed file output
		fout << "0\n1\n";

		do
		{
			// bump the iteration index for next fibonacci number in sequence
			idx++; 

			// Compute f(idx) = f(idx-1) + f(idx-2)
			fn=fn_minus_1 + fn_minus_2;

			// Check for overflow detected by non-increasing sequence
			if(!(fn >= fn_minus_1))
				break;

			fn_minus_2 = fn_minus_1;
			fn_minus_1 = fn;

			// Debug console output
			cout << "idx=" << idx << ", fn=" << fn << "\n";

			// Fibonacci pre-computed file output
			fout << fn << "\n";

		} while(idx < n);

		if((idx < n) || (!(fn >= fn_minus_1)
			
			)) // we exited on overflow rather than completion of sequence
		{
			cout << "fibonacci of " << idx << " = " << fn << " is AN OVERFLOW\n";
			cout << "fibonacci of " << (idx-1) << " = " << fn_minus_1 << " is LAST COMPUTABLE for storage type\n";
			cerr << "Fibonacci OVERFLOW\n";
		}
		else if(idx == n) // expected successful exit condition
		{
			cout << "fibonacci of " << idx << " = " << fn << "\n";
		}
		else
			cerr << "Fibonacci SEQUENCE ERROR\n";
			
	}

	fout.close();

	return 0;
}

