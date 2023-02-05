#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Draw.h"
using namespace std;
//Fajekgh3lr5h2!@fs9

int main (){
	Draw draw;

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

	draw.render(defaultSinX);


Start:

	char graphAPolynomial;

	std::cout << "========================== \r\n"
				<< "Graph some polynomials? (y/n) \r\n"
				<< "========================== \r\n";
	std::cin >> graphAPolynomial;
	if (cin.fail() || (graphAPolynomial != 'n' && graphAPolynomial != 'y'))
	{
		cin.clear();
		cin.ignore(1024, '\n');
		std::cout << " \r\n \r\n Please answer (y/n).... \r\n \r\n";
		goto Start;
	}
	if (graphAPolynomial == 'n')
	{
		std::cout << "=== Thanks for Graphing!! ====";
		return 0;
	}
	std::cout << "========================== \r\n"
				<< "\r\n \r\n"
				<< "How many would you like to graph? \r\n";
	int polyCount;
	std::cin >> polyCount;

	std::cout << "========================== \r\n"
				<< "\r\n \r\n"
				<< "What's the highest degree you'd like to graph? \r\n";
	int maxDegree;
	std::cin >> maxDegree;

	/* //extract method construct polynomialArray;
		// and each of the other parts of main.

		polynomialArray = {
			...,
			{ 
				a_i0, a_i1,...,a_imaxDegree
			}
		}_{0 <= i <= polyCount-1}


	*/
	vector<float> zeroPolynomialOfMaxDegree(maxDegree+1, 0);
	vector<vector<float> > polynomialArray(polyCount, zeroPolynomialOfMaxDegree);

	for (int i = 0; i < polyCount; i++)
	{
		std::cout << "============================="
					<< "Please define the coefficients for Polynomial # " << i << "\r\n";  
		for (int j = maxDegree; j > -1; j--)
		{
			float jthCoefficient = 0.0;
			std::cout << "Coefficient for x to the " << j << " : ";
			std::cin >> jthCoefficient;
			polynomialArray.at(i).at(j) = jthCoefficient;
		}
	}


	std::cout << "Ok. Here we go! \r\n";
	draw.render(polynomialArray);

	goto Start;

	return 0;
};