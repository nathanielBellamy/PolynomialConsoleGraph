#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Compute.h"
#include "Settings.h"
using namespace std;

	double Compute::execute(vector<double> polynomial, double x) {
		double output = 0.0;
		for (int i = polynomial.size()-1; i > -1; --i)
		{ 
			output += polynomial.at(i) * pow(x, i);
		}
		return output;
	};

	int Compute::minimumIndexWithinYPlusEpsilon(vector<double> imageOfX, double y, Settings settings) {
		for (int i = 0; i < imageOfX.size(); i++)
		{	
			double pointOnGraph = imageOfX.at(i);
			if (abs(pointOnGraph - y) < settings.epsilon)
			{
				return i;
			}
		}	
		return -1;
	};

	vector<vector<double> > Compute::computeImageArray(vector<vector<double> > polynomialArray,
                                                    vector<vector<double> > imageArray,
                                                    Settings settings) {
    double stepWidth = Settings::stepWidth(settings);
		for (int i = 0; i < polynomialArray.size(); i++)
		{
			vector<double> thisPolynomial = polynomialArray.at(i);
      int xStepCount = Settings::xStepCount(settings);
			for (int j = 0; j <= xStepCount; j++)
			{
				double x = settings.xMin + j * stepWidth; // j = (x - xMin)/stepWidth
				imageArray.at(i).at(j) = execute(thisPolynomial, x);		
			}
		}
		return imageArray;
	};
