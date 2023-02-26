#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Compute.h"
#include "Settings.h"
using namespace std;

	float Compute::execute(vector<float> polynomial, float x) {
		float output = 0.0;
		for (int i = polynomial.size()-1; i > -1; --i)
		{ 
			output += polynomial.at(i) * pow(x, i);
		}
		return output;
	};

	int Compute::minimumIndexWithinYPlusEpsilon(vector<float> imageOfX, float y, Settings settings) {
		for (int i = 0; i < imageOfX.size(); i++)
		{	
			float pointOnGraph = imageOfX.at(i); 
			if (abs(pointOnGraph - y) < settings.epsilon)
			{
				return i;
			}
		}	
		return -1;
	};

	vector<vector<float> > Compute::computeImageArray(vector<vector<float> > polynomialArray,
                                                    vector<vector<float> > imageArray,
                                                    Settings settings) {
    float stepWidth = Settings::stepWidth(settings);
		for (int i = 0; i < polynomialArray.size(); i++)
		{
			vector<float> thisPolynomial = polynomialArray.at(i);
      int xStepCount = Settings::xStepCount(settings);
			for (int j = 0; j <= xStepCount; j++)
			{
				float x = settings.xMin + j * stepWidth; // j = (x - xMin)/stepWidth
				imageArray.at(i).at(j) = execute(thisPolynomial, x);		
			}
		}
		return imageArray;
	};
