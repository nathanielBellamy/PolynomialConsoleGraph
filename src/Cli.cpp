#include<iostream>
#include<string>
#include<vector>
#include "Cli.h"
#include "CliGet.h"
#include "CliValidate.h"
#include "Draw.h"
#include "Settings.h"
using namespace std;

  void Cli::intro(Settings &settings) {
    Draw draw;

    static const double sinXArr[12] = { 0.0, 2, 0.0, -1.6666666666, 0.0, .0083333333, 0.0, -0.0001984, 0.0, 0.00000275573192239858, 0.0, -0.000000025052108 };
    static const double negSinXArr[12] = { 0.0, -2, 0.0, 1.6666666666, 0.0, -.0083333333, 0.0, 0.0001984, 0.0, -0.00000275573192239858, 0.0, 0.000000025052108 };

    vector<double> sinXVec (sinXArr, sinXArr + sizeof(sinXArr) / sizeof(sinXArr[0]) );
    vector<double> negSinXVec (negSinXArr, negSinXArr + sizeof(negSinXArr) / sizeof(negSinXArr[0]) );
    vector<double> zeroPolynomialOfDegreeTwelve (12, 0);

    vector<vector<double> > defaultSinX(2, zeroPolynomialOfDegreeTwelve);
    defaultSinX.at(0) = sinXVec;
    defaultSinX.at(1) = negSinXVec;

    std::cout << "\r\n=========================== \r\n"
          << "Welcome to Polynomial Console Graph \r\n"
          << "=========================== \r\n";

    draw.render(defaultSinX, settings);
  };

  bool Cli::openingQuestion(bool &firstPass) {
    CliGet get;
    if (firstPass) {
      firstPass = false;
      std::cout << "========================== \n"
        << "Graph some polynomials? \n"
        << "========================== \n";
    } else {
      std::cout << "========================== \n"
        << "Go Again? \n"
        << "========================== \n";
    }

    return get.cliyesno();
  };

  void Cli::outro() {
    std::cout << "\n========== Thanks for stopping by! ==========";
  };

  void Cli::setDisplaySize(Settings &settings) {
    CliGet get;
    CliValidate valid;

    std::cout << "============"
      << "The default display size is 64 characters by 32 characters."
      << " Do you want to adjust the size for your graph?";
    bool adjustDisplaySize;
    adjustDisplaySize = get.cliyesno();

    if (adjustDisplaySize){
      SetWidth:
        std::cout << "Set Display Width: ";
        int displayWidth;
        displayWidth = get.cliInt();
        if (valid.displaySize(displayWidth)) {
          settings.displayWidth = displayWidth;
        } else {
          goto SetWidth;
        }

      SetHeight:
        std::cout << "Set Display Height: ";
        int displayHeight;
        displayHeight = get.cliInt();
        if (valid.displaySize(displayHeight)) {
          settings.displayHeight = displayHeight;
        } else {
          goto SetHeight;
        }
    }
  };

  void Cli::setEpsilon(Settings &settings) {
    CliGet get;
    CliValidate valid;

    std::cout << "============"
      << "Adjust Epsilon? "
      << "(If you are having trouble seeing your graph, try increasing this value.)";
    bool adjustEpsilon;
    adjustEpsilon = get.cliyesno();

    if (adjustEpsilon) {
      SetEpsilon:
        std::cout << "Set Epsilon: ";
        double epsilon;
        epsilon = get.cliDouble();
        if (valid.epsilon(epsilon)) {
          settings.epsilon = epsilon;
        } else {
          goto SetEpsilon;
        }
    }
  };

  vector<vector<double> > Cli::setPolynomials(Settings &settings) {
    CliGet get;
    CliValidate valid;

    std::cout << "========================== \n"
          << "\n \n"
          << "How many would you like to graph? \n";

    SetPolyCount:
      int polyCount;
      polyCount = get.cliInt();
      if (!valid.polyCount(polyCount)) {
        goto SetPolyCount;
      }
    
    std::cout << "\n Entered: ";
    std::cout << polyCount;

    std::cout << "\n ========================== \n"
          << "\n \n"
          << "What's the highest degree you'd like to graph? \n";

    SetMaxDegree:
      int maxDegree;
      maxDegree = get.cliInt();
      if (!valid.maxDegree(maxDegree)) {
        goto SetMaxDegree;
      }

    /*
      polynomialArray = {
        ...,
        {
          a_i0, a_i1,...,a_imaxDegree
        }
      }_{0 <= i <= polyCount-1}
    */

    vector<double> zeroPolynomialOfMaxDegree(maxDegree+1, 0);
    vector<vector<double> > polynomialArray(polyCount, zeroPolynomialOfMaxDegree);

    for (int i = 0; i < polyCount; i++)
    {
      std::cout << "============================="
            << "Please define the coefficients for Polynomial # " << i << "\n";
      for (int j = maxDegree; j > -1; j--)
      {
        std::cout << "Coefficient for x to the " << j << " : ";
        double jthCoefficient = 0.0;
        jthCoefficient = get.cliDouble();
        polynomialArray.at(i).at(j) = jthCoefficient;
      }
    }

    return polynomialArray;
  };

  void Cli::setWindow(Settings &settings) {
    CliGet get;
    CliValidate valid;

    std::cout << "============"
      << "The default window is `[-1.3, 1.3] x [-1.3, 1.3]. \n"
      << "Do you want to adjust the window for your graph?";
    bool adjustWindow;
    adjustWindow = get.cliyesno();

    if (adjustWindow) {
      SetXAxis:
        double xMin;
        double xMax;
        std::cout << "Set Min x: ";
        xMin = get.cliDouble();
        std::cout << "Set Max x: ";
        xMax = get.cliDouble();

        if (valid.axisInterval(xMin, xMax)) {
          settings.xMin = xMin;
          settings.xMax = xMax;
        } else {
          goto SetXAxis;
        }

      SetYAxis:
        double yMin;
        double yMax;
        std::cout << "Set Min y: ";
        yMin = get.cliDouble();
        std::cout << "Set Max y: ";
        yMax = get.cliDouble();

        if (valid.axisInterval(yMin, yMax)) {
          settings.yMin = yMin;
          settings.yMax = yMax;
        } else {
          goto SetYAxis;
        }
    }
  };

