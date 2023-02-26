#include<iostream>
#include<string>
#include<vector>
#include "Cli.h"
#include "CliValidate.h"
#include "Draw.h"
#include "Settings.h"
using namespace std;

  void Cli::intro(Settings &settings) {
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

    draw.render(defaultSinX, settings);
  };

  bool Cli::openingQuestion(bool &firstPass) {
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

    return yesno();
  };

  void Cli::outro() {
    std::cout << "\n========== Thanks for stopping by! ==========";
  }

  void Cli::setDisplaySize(Settings &settings) {
    CliValidate valid;

    std::cout << "============"
      << "The default display size is 80 characters by 30 characters."
      << " Do you want to adjust the size for your graph?";
    bool adjustDisplaySize;
    adjustDisplaySize = yesno();

    if (adjustDisplaySize){
      SetWidth:
        int displayWidth;
        std::cout << "Set Display Width: ";
        std::cin >> displayWidth;
        if (valid.displaySize(displayWidth)) {
          settings.displayWidth = displayWidth;
        } else {
          goto SetWidth;
        }

      SetHeight:
        int displayHeight;
        std::cout << "Set Display Height: ";
        std::cin >> displayHeight;
        if (valid.displaySize(displayHeight)) {
          settings.displayHeight = displayHeight;
        } else {
          goto SetHeight;
        }
    }
  };

  void Cli::setEpsilon(Settings &settings) {
    CliValidate valid;

    std::cout << "============"
      << "Adjust Epsilon? "
      << "(If you are having trouble seeing your graph, try increasing this value.)";
    bool adjustEpsilon;
    adjustEpsilon = yesno();

    if (adjustEpsilon) {
      SetEpsilon:
        int epsilon;
        std::cout << "Set Epsilon: ";
        std::cin >> epsilon;
        if (valid.epsilon(epsilon)) {
          settings.epsilon = epsilon;
        } else {
          goto SetEpsilon;
        }
    }
  };

  vector<vector<float> > Cli::setPolynomials(Settings &settings) {
    CliValidate valid;
    std::cout << "========================== \n"
          << "\n \n"
          << "How many would you like to graph? \n";

    SetPolyCount:
      int polyCount;
      std::cin >> polyCount;
      if (!valid.polyCount(polyCount)) {
        goto SetPolyCount;
      }

    std::cout << "========================== \n"
          << "\n \n"
          << "What's the highest degree you'd like to graph? \n";

    SetMaxDegree:
      int maxDegree;
      std::cin >> maxDegree;
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

    vector<float> zeroPolynomialOfMaxDegree(maxDegree+1, 0);
    vector<vector<float> > polynomialArray(polyCount, zeroPolynomialOfMaxDegree);

    for (int i = 0; i < polyCount; i++)
    {
      std::cout << "============================="
            << "Please define the coefficients for Polynomial # " << i << "\n";
      for (int j = maxDegree; j > -1; j--)
      {
        float jthCoefficient = 0.0;
        std::cout << "Coefficient for x to the " << j << " : ";
        std::cin >> jthCoefficient;
        polynomialArray.at(i).at(j) = jthCoefficient;
      }
    }

    return polynomialArray;
  };

  void Cli::setWindow(Settings &settings) {
    CliValidate valid;
    std::cout << "============"
      << "The default window is `[-1.3, 1.3] x [-1.3, 1.3]. \n"
      << "Do you want to adjust the window for your graph?";
    bool adjustWindow;
    adjustWindow = yesno();

    if (adjustWindow) {
      SetXAxis:
        float xMin;
        float xMax;
        std::cout << "Set Min x: ";
        std::cin >> xMin;
        std::cout << "Set Max x: ";
        std::cin >> xMax;

        if (valid.axisInterval(xMin, xMax)) {
          settings.xMin = xMin;
          settings.xMax = xMax;
        } else {
          goto SetXAxis;
        }

      SetYAxis:
        float yMin;
        float yMax;
        std::cout << "Set Min y: ";
        std::cin >> yMin;
        std::cout << "Set Max y: ";
        std::cin >> yMax;

        if (valid.axisInterval(yMin, yMax)) {
          settings.yMin = yMin;
          settings.yMax = yMax;
        } else {
          goto SetYAxis;
        }
    }
  };

  bool Cli::yesno() {
    YesNo:
      char result;
      std::cout << " (y/n) ";
      std::cin >> result;
      if (cin.fail() || (result != 'n' && result != 'y')) {
        cin.clear();
        cin.ignore(1024, '\n');
        goto YesNo;
      }
      return result == 'y';
  };
