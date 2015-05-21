/*
 * main.cpp
 *
 *  Created on: May 20, 2015
 *      Author: trystan
 */




#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "mathy.h"

using namespace std;

int main() {

	cout << "What is the type of your equation? (Linear (l), Exponential (e), Log(g), or Absolute (a)) ";
	string equation;
	cin >> equation;

	//cout << "Input all further values not as fractions. " << endl;

	cout << "What is the smallest x value? ";
	double startXValue;
	cin >> startXValue;

	cout << "What is the biggest x value? ";
	double endXValue;
	cin >> endXValue;

	cout << "What is the x interval? ";
	double xInterval;
	cin >> xInterval;


	for(char &c : equation)
		c = tolower(c);

	if((equation == "linear" || equation == "l") || (equation == "absolute" || equation == "a")) {

		bool abs = false;
		if(equation == "absolute" || equation == "a")
			abs = true;

		doLinear(startXValue, endXValue, xInterval, abs);

	} else if(equation == "exponential" || equation == "e") {
		doExp(startXValue, endXValue, xInterval);

	} else if(equation == "log" || equation == "g") {
		doLog(startXValue, endXValue, xInterval);

	}

	return 0;
}
