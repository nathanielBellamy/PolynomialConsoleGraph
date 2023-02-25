#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Cli.h"
#include "Draw.h"
#include "Settings.h"
using namespace std;

int main (){
  Cli cli;
	Draw draw;
  Settings settings;

	static const float sinXArr[12] = { 0.0, 2, 0.0, -1.6666666666, 0.0, .0083333333, 0.0, -0.0001984, 0.0, 0.00000275573192239858, 0.0, -0.000000025052108 };
	static const float negSinXArr[12] = { 0.0, -2, 0.0, 1.6666666666, 0.0, -.0083333333, 0.0, 0.0001984, 0.0, -0.00000275573192239858, 0.0, 0.000000025052108 };


	vector<float> sinXVec (sinXArr, sinXArr + sizeof(sinXArr) / sizeof(sinXArr[0]) );
	vector<float> negSinXVec (negSinXArr, negSinXArr + sizeof(negSinXArr) / sizeof(negSinXArr[0]) );
	vector<float> zeroPolynomialOfDegreeTwelve (12, 0);

	vector<vector<float> > defaultSinX(2, zeroPolynomialOfDegreeTwelve);
	defaultSinX.at(0) = sinXVec;
	defaultSinX.at(1) = negSinXVec;

	std::cout << "\r\n=========================== \r\n"
				<< "Welcome to Polynomial Console Graph \r\n"
				<< "=========================== \r\n";

	draw.render(defaultSinX, settings);


Start:

	char graphPolynomials;
	std::cout << "========================== \r\n"
				<< "Graph some polynomials? (y/n) \r\n"
				<< "========================== \r\n";
	std::cin >> graphPolynomials;
	if (cin.fail() || (graphPolynomials != 'n' && graphPolynomials != 'y'))
	{
		cin.clear();
		cin.ignore(1024, '\n');
		std::cout << " \r\n \r\n Please answer (y/n).... \r\n \r\n";
		goto Start;
	}
	if (graphPolynomials == 'n')
	{
		std::cout << "=== Thanks for Graphing!! ====";
		return 0;
	}

  vector<vector<float> > polynomialArray;
  polynomialArray = cli.setPolynomials(settings);
  cli.setWindow(settings);
  cli.setDisplaySize(settings);
  cli.setEpsilon(settings);

	std::cout << "Ok. Here we go! \r\n";
	draw.render(polynomialArray, settings);

	goto Start;

	return 0;
};
