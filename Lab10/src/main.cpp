/*********************************************************
 Author: Martin Edmudns
 Class: CS 162-400
 Date: 03/14/19
 Project: Lab 10
 Description: A simple program to time the execution of calculation
 fibonacci numbers by recursion and iteration.


 Source for implementing the time library:
 http://www.cplusplus.com/reference/ctime/clock/

**********************************************************/



#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>


#define FIB_NUM 400000

/*
Recursive Fibonacci source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*/
int fibR(const int& n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return (fibR(n -  2) + fibR( n - 1));
}

/*
Iterative Fibonacci source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*/
int fibIter(const unsigned& fib) {
	unsigned first = 0;
	unsigned second = 1;
	unsigned counter = 2;
	while (counter < fib)
	{
	    unsigned temp = second;
	    second = first + second;
	    first = temp;
	    ++counter;
	}
	 if (fib == 0)
	         return 0;
	 else
	         return first + second;
	
}


int main() {


	const unsigned fib = FIB_NUM;

	int value;		//store fib number-testing
	
	clock_t timer;

	std::cout << "Time for iterartion for fib of " << fib << std::endl;

	timer = clock();
	value = fibIter(fib);
	timer = clock() - timer;

	std::cout << "\t" << (float)timer << "   " << ((float)timer) / CLOCKS_PER_SEC << std::endl;

	std::cout << "Time for recursion for fib of " << fib << std::endl;

	timer = clock();
	//value = fibR(fib);		//comment out for fib > 38
	timer = clock() - timer;

	std::cout << "\t" << (float)timer << "   " << ((float)timer) / CLOCKS_PER_SEC << std::endl;


	return 0;
}