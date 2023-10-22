#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Compute.h"
#include "Settings.h"
using namespace std;

  double Compute::execute(vector<double> polynomial, double x) {
    double output = 0.0;
    for (int i = polynomial.size()-1; i > -1; --i) { 
      output += polynomial.at(i) * pow(x, i);
    }
    return output;
  };

  vector<double> Compute::piecewsieImage(vector<vector<double> > polynomialArray, Settings settings)
  {
    int xStepCount = Settings::xStepCount(settings);
    vector<double> res(xStepCount, 0);
    int polynomialCount = polynomialArray.size();

    int currPolynomialIndex;
    if (xStepCount <= polynomialCount)
    {
      // do as many as you can in single width columns
      for (int i = 0; i < xStepCount; i++)
      {
        double x = settings.xMin + i * xStepCount;
        res.at(i) = execute(polynomialArray.at(i), x);
      }
    }
    else
    {
      // TODO
      for (int i = 0; i < xStepCount; i++)
      {
        double x = settings.xMin + i * xStepCount;

        int quotient = std::floor((1.0 * xStepCount) / (1.0 * polynomialCount));
        int remainder = xStepCount % polynomialCount;
        vector<int> stepsPerPolynomial(polynomialCount, quotient);

        // add remainder steps to middle intervals
        int extraMidFirstIndex = std::floor((polynomialCount - remainder) / 2.0);
        for (i = extraMidFirstIndex; i < remainder; i++)
        {
          stepsPerPolynomial.at(i) += 1;
        }

        // compute which polynomial to use at each x step
        vector<int> polynomialAtStep(xStepCount, 0);
        int pasIndex = 0;
        for (i = 0; i < polynomialCount; i++)
        {
          int j = 0;
          for (j = 0; j < stepsPerPolynomial.at(i); j++)
          {
            polynomialAtStep.at(pasIndex) = i;
            pasIndex += 1;
          }
        }

        // execute correct polynomial at each x step 
        for (i = 0; i < xStepCount; i++)
        {
          res.at(i) = execute(polynomialArray.at(polynomialAtStep.at(i)), x);
        }
      }
    }
    
    return res;
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
    for (int i = 0; i < polynomialArray.size(); i++) {
      vector<double> thisPolynomial = polynomialArray.at(i);
      int xStepCount = Settings::xStepCount(settings);
      for (int j = 0; j <= xStepCount; j++) {
        double x = settings.xMin + j * stepWidth; // j = (x - xMin)/stepWidth
        imageArray.at(i).at(j) = execute(thisPolynomial, x);    
      }
    }
    return imageArray;
  };
