#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Compute.h"
#include "Settings.h"
#include "../../Constants.h" // from nbsdsp repo containing this submodule
using namespace std;

  double Compute::execute(vector<double> polynomial, double x) 
  {
    double output = 0.0;
    for (int i = polynomial.size()-1; i > -1; --i) 
    { 
      output += polynomial.at(i) * pow(x, i);
    }
    return output;
  };

  double Compute::execute_a(double (*polynomial)[POLYNOMIAL_DEGREE_P1], double x) 
  {
    double output = 0.0;
    for (int i = 0; i < POLYNOMIAL_DEGREE_P1; i++) 
    { 
      // printf("\npoly %i: %f", i, (*polynomial)[i]);
      output += (*polynomial)[i] * pow(x, i);
    }
    return output;
  };

  bool Compute::withinEpsilon(vector<double> image, int i, double y, Settings *settings)
  {
    return abs(image[i] - y) < settings->epsilon;
  };

  bool Compute::withinEpsilon_a(double (*image)[EQ_IMAGE_WIDTH], int i, double y, Settings *settings)
  {
    return abs((*image)[i] - y) < settings->epsilon;
  };

  void Compute::piecewiseImage(
    double (*polynomialArray)[POLYNOMIAL_ARRAY_LENGTH][POLYNOMIAL_DEGREE_P1], 
    double (*image)[EQ_IMAGE_WIDTH], 
    Settings *settings
  )
  {
    {
      int stepsPerPolynomial[POLYNOMIAL_ARRAY_LENGTH];
      for (int i = 0; i < POLYNOMIAL_ARRAY_LENGTH; i++)
      {
        stepsPerPolynomial[i] = 5;
      }

      // compute which polynomial to use at each x step
      int polynomialAtStep[EQ_IMAGE_WIDTH] = { 2 };
      int pasIndex = 0;
      for (int i = 0; i < POLYNOMIAL_ARRAY_LENGTH; i++)
      {
        for (int j = 0; j < stepsPerPolynomial[i]; j++)
        {
          if (pasIndex < EQ_IMAGE_WIDTH)
          {
            polynomialAtStep[pasIndex] = i;
            pasIndex += 1;
            // printf("\n pasIndex: %i", pasIndex);
          }
        }
      }

      // execute correct polynomial at each x step 
      for (int i = 0; i < EQ_IMAGE_WIDTH; i++)
      {
        double x = settings->xMin + i * settings->stepWidth;
        // for (int k = 0; k < POLYNOMIAL_DEGREE_P1; k++)
        // {
        //   printf("\npA paS %i: %f", i, (*polynomialArray)[polynomialAtStep[i]][k]);
        // }
        (*image)[i] = execute_a(&(*polynomialArray)[polynomialAtStep[i]], x);
        // printf("\nimage i: %f", (*image)[i]);
      }
    }
  };

  int Compute::minimumIndexWithinYPlusEpsilon(vector<double> imageOfX, double y, Settings *settings) {
    for (int i = 0; i < imageOfX.size(); i++) 
    { 
      double pointOnGraph = imageOfX.at(i);
      if (abs(pointOnGraph - y) < settings->epsilon)
      {
        return i;
      }
    } 
    return -1;
  };

  vector<vector<double> > Compute::computeImageArray(vector<vector<double> > polynomialArray,
                                                     vector<vector<double> > imageArray,
                                                     Settings settings) {
    double stepWidth = Compute::stepWidth(&settings);
    for (int i = 0; i < polynomialArray.size(); i++) {
      vector<double> thisPolynomial = polynomialArray.at(i);
      int xStepCount = Compute::xStepCount(&settings);
      for (int j = 0; j <= xStepCount; j++) {
        double x = settings.xMin + j * stepWidth; // j = (x - xMin)/stepWidth
        imageArray.at(i).at(j) = execute(thisPolynomial, x);    
      }
    }
    return imageArray;
  };


  double Compute::stepWidth(Settings *settings) {
    return (settings->xMax - settings->xMin) / EQ_IMAGE_WIDTH;
  }

  double Compute::stepHeight(Settings *settings) {
    return (settings->yMax - settings->yMin) / EQ_IMAGE_HEIGHT;
  }

  int Compute::xStepCount(Settings *settings) {
    return (settings->xMax - settings->xMin) / EQ_IMAGE_WIDTH;
  }
