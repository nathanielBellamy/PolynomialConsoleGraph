#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Draw.h"
#include "Settings.h"
using namespace std;

int main (){
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

  char adjustWindow;
  std::cout << "============"
    << "The default window is `[-1.3, 1.3] x [-1.3, 1.3]."
    << " Do you want to adjust the window for your graph? (y/n)";
  std::cin >> adjustWindow;

  if (adjustWindow == 'y')
  {
    // TODO: validate
    float xMin;
    std::cout << "Set Min x: ";
    std::cin >> xMin;
    settings.xMin = xMin;

    float xMax;
    std::cout << "Set Max x: ";
    std::cin >> xMax;
    settings.xMax = xMax;

    float yMin;
    std::cout << "Set Min y: ";
    std::cin >> yMin;
    settings.yMin = yMin;

    float yMax;
    std::cout << "Set Max x: ";
    std::cin >> yMax;
    settings.yMax = yMax;
  }

  char adjustDisplaySize;
  std::cout << "============"
    << "The default display size is 80 characters by 30 characters."
    << " Do you want to adjust the size for your graph? (y/n)";
  std::cin >> adjustDisplaySize;

  if (adjustDisplaySize == 'y')
  {
    // TODO: validate
    int displayWidth;
    std::cout << "Set Display Width: ";
    std::cin >> displayWidth;
    settings.displayWidth = displayWidth;

    float displayHeight;
    std::cout << "Set Display Height: ";
    std::cin >> displayHeight;
    settings.displayHeight = displayHeight;
  }

	std::cout << "Ok. Here we go! \r\n";
	draw.render(polynomialArray, settings);

	goto Start;

	return 0;
};
