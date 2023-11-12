#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Compute.h"
#include "Settings.h"
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

  double Compute::execute_a(double (*polynomial)[16], double x) 
  {
    double output = 0.0;
    for (int i = 0; i < 16; i++) 
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

  bool Compute::withinEpsilon_a(double (*image)[80], int i, double y, Settings *settings)
  {
    return abs((*image)[i] - y) < settings->epsilon;
  };

  void Compute::piecewsieImage(double (*polynomialArray)[16][16], double (*image)[80], Settings *settings)
  {
    int polynomialCount = 16;

    // if (80 <= polynomialCount)
    // {
    //   // do as many as you can in single width columns
    //   for (int i = 0; i < 80; i++)
    //   {
    //     double x = settings->xMin + i * settings->stepWidth;
    //     (*image)[i] = execute_a(polynomialArray[i], x);
    //   }
    // }
    // else
    {
      // int quotient = 5; // std::floor(80.0 / (1.0 * polynomialCount));
      // int remainder = 0;// 80 % polynomialCount;
      int stepsPerPolynomial[16];
      for (int i = 0; i < 16; i++)
      {
        stepsPerPolynomial[i] = 5;
      }

      // // add remainder steps to middle intervals
      // int extraMidFirstIndex = 0; // std::floor((polynomialCount - remainder) / 2.0);
      // for (int j = 0; j < remainder; j++)
      // {
      //   stepsPerPolynomial[extraMidFirstIndex + j] += 1;
      // }

      // compute which polynomial to use at each x step
      int polynomialAtStep[80];
      int pasIndex = 0;
      for (int i = 0; i < polynomialCount; i++)
      {
        for (int j = 0; j < stepsPerPolynomial[i]; j++)
        {
          if (pasIndex < 80)
          {
            polynomialAtStep[pasIndex] = i;
            pasIndex += 1;
            // printf("\n pasIndex: %i", pasIndex);
          }
        }
      }

      // execute correct polynomial at each x step 
      for (int i = 0; i < 80; i++)
      {
        double x = settings->xMin + i * settings->stepWidth;
        // for (int k = 0; k < 16; k++)
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
    return (settings->xMax - settings->xMin)/settings->displayWidth;
  }

  double Compute::stepHeight(Settings *settings) {
    return (settings->yMax - settings->yMin)/settings->displayHeight;
  }

  int Compute::xStepCount(Settings *settings) {
    return (settings->xMax - settings->xMin) / settings->stepWidth;
  }
