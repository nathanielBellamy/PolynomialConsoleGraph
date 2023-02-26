#include<iostream>
#include<string>
#include<vector>
#include "Cli.h"
#include "CliValidate.h"
#include "Settings.h"
using namespace std;

  void Cli::setDisplaySize(Settings &settings) {
    CliValidate valid;
    char adjustDisplaySize;
    std::cout << "============"
      << "The default display size is 80 characters by 30 characters."
      << " Do you want to adjust the size for your graph? (y/n)";
    std::cin >> adjustDisplaySize;

    if (adjustDisplaySize == 'y'){
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
    char adjustEpsilon;
    std::cout << "============"
      << "Adjust Epsilon? "
      << "(If you are having trouble seeing your graph, try increasing this value.) (y/n)";
    std::cin >> adjustEpsilon;

    if (adjustEpsilon == 'y') {
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
    char adjustWindow;
    std::cout << "============"
      << "The default window is `[-1.3, 1.3] x [-1.3, 1.3]. \n"
      << "Do you want to adjust the window for your graph? (y/n) \n";
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
      std::cout << "Set Max y: ";
      std::cin >> yMax;
      settings.yMax = yMax;
    }
  };
