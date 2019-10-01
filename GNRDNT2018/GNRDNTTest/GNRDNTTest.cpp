// GNRDNTTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <GNRDNT2018.h>
#include <iostream>
#include <stdio.h>

int main()
{
	double l = 4.7121201260;
	double p = 51.7286012740;
	double h = 301.7981;
	double x, y, z;
	printf("input: %.10lf %.10lf %.4lf\r\n", l, p, h);
	etrs2rdnap(l, p, h, &x, &y, &z);
	printf("RD/NAP: %.4lf %.4lf %.4lf\r\n", x, y, z);
	rdnap2etrs(x, y, z, &l, &p, &h);
	printf("check: %.10lf %.10lf %.4lf\r\n", l, p, h);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
