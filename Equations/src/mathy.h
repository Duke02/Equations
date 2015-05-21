/*
 * mathy.h
 *
 *  Created on: May 20, 2015
 *      Author: trystan
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef MATHY_H_
#define MATHY_H_



vector<double> doFractionalCoefficient(string input) {
	//Make the denominator and numerator
	vector<double> output(2);


	bool isFraction = false;
	string numerator;
	string denominator;
	//Position of /
	int posOfDiv = input.size()-1;
	//Loop through the input string
	for(auto i = 0; i != input.size(); i++) {
		char &c = input[i];

		if(c == '/') {
			posOfDiv = i;
			isFraction = true;
			break;
		}
	}

	if(isFraction) {
		numerator = input.substr(0, posOfDiv);
		denominator = input.substr(posOfDiv + 1);
	} else {
		numerator = input;
		denominator = "1";
	}

	output[0] = stod(numerator);
	output[1] = stod(denominator);

	return output;
}

double doCoeffOfX(string input) {
	for(int i = 0; i != input.size(); i++) {
		char &c = input[i];
		if(c == 'x')
			input = input.substr(0, i);
			break;
	}

	vector<double> coeff = doFractionalCoefficient(input);

	return coeff[0]/coeff[1];
}

double log(double n, double base) {
	return log10(n)/log10(base);
}

void doLinear(double startXValue, double endXValue, double xInterval, bool absolute) {
	cout << "What is the slope? ";
	string slope;
	cin >> slope;

	cout << "What is the y-intercept? ";
	string yInt;
	cin >> yInt;


	string kString = "0/1";
	if(absolute) {
		cout << "What is the k?";
		cin >> kString;
	}

	vector<double> mV = doFractionalCoefficient(slope);
	vector<double> yV = doFractionalCoefficient(yInt);
	vector<double> kV = doFractionalCoefficient(kString);

	double m = mV[0]/mV[1];
	double b = yV[0]/yV[1];
	double k = kV[0]/kV[1];

	cout << "y=" << m;
	if(absolute){
		cout << "|x";
		if(k != 0)
			cout << "+" << k;
		cout << "|";
	} else
		cout << "x";

	if(b != 0)
		cout << "+" << b;
	cout << endl;

	double y = 0;
	double X;
	for(auto x = startXValue; x != endXValue + 1; x += xInterval) {
		if(x > endXValue)
			break;
		X = x;
		if(absolute)
			X = abs(x);

		y = m*X + b;

		cout << "y=" << y << " (x=" << x << ")" << endl;
	}

}

void doExp(double startXValue, double endXValue, double xInterval) {

	cout << "What is the first power of x? ";
	int power;
	cin >> power;

	int term = 0;
	vector<double> coefficients(abs(power+1), 1);

	for(auto &c : coefficients) {
		cout << "What is the coefficient of the term with x ^"
				<< power-term << "? ";
		cin >> c;
		term++;
	}

	cout << "y=";
	term = 0;
	for(auto &c : coefficients) {
		if(c != 0 && c != 1)
			cout << c << "x^" << power-term;
		else if(c == 1)
			cout << "x^" << power-term;

		if(c != coefficients[coefficients.size()-1] && coefficients[term+1] != 0)
			cout << "+";
		term++;
	}
	cout << endl;

	double y;
	term = 0;
	for(auto x = startXValue; x != endXValue+1; x+= xInterval) {
		y = 0;
		for(auto &c : coefficients) {
			y += c * std::pow(x, power - term);
		}
		cout << "y=" << y << "(x=" << x << ")" << endl;
	}
}

void doLog(double startXValue, double endXValue, double xInterval) {
	//What is base and N
	cout << "What is the base? ";
	string baseString;
	cin >> baseString;

	cout << "What is N? ";
	string nString;
	cin >> nString;

	bool xN, xBase = false;

	double n, base = 0;

	for(auto &c : nString) {
		if(c == 'x')
			xN = true;
	}


	double nXCoeff = 1;
	if(!xN)
		n = stod(nString);
	else
		nXCoeff = doCoeffOfX(nString);

	for(auto &c : baseString) {
		if(c == 'x')
			xBase = true;
	}

	double baseXCoeff = 1;
	if(!xBase)
		base = stod(baseString);
	else
		baseXCoeff = doCoeffOfX(baseString);



	cout << "y=log" << baseString << "(" << nString << ")" << endl;

	double y;
	for(auto x = startXValue; x != endXValue + 1; x += xInterval) {

		if(x > endXValue)
			break;

		if(!xBase && !xN)
			y = log(n * nXCoeff, base*baseXCoeff);
		else if(xBase && !xN)
			y = log(n* nXCoeff, x*baseXCoeff);
		else if(!xBase && xN)
			y = log(x* nXCoeff, base*baseXCoeff);
		else
			y = log(x* nXCoeff,x*baseXCoeff);

		cout << "y=" << y << " (x=" << x << ")" << endl;
	}

}

#endif /* MATHY_H_ */
