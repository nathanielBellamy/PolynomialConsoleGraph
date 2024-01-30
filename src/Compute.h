#ifndef Compute_H
#define Compute_H
#include<vector>
#include "Settings.h"
#include "../../Constants.h" // from nbsdsp repo containing this submodule
using namespace std;

class Compute {

	public:
		static double execute(vector<double> polynomial, double x);
    static double execute_a(double (*polynomial)[POLYNOMIAL_DEGREE_P1], double x);
		static vector<vector<double> > computeImageArray(
      vector<vector<double> > polynomialArray, 
      vector<vector<double> > imageArray, 
      Settings settings
    );
    static void piecewiseImage(
      double (*polynomialArray)[POLYNOMIAL_ARRAY_LENGTH][POLYNOMIAL_DEGREE_P1], 
      double (*image)[EQ_IMAGE_WIDTH], 
      Settings *settings
    );
		static int minimumIndexWithinYPlusEpsilon(vector<double> imageOfX, double y, Settings *settings);
    static bool withinEpsilon(vector<double> image, int i, double y, Settings *setting);
    static bool withinEpsilon_a(double (*image)[EQ_IMAGE_WIDTH], int i, double y, Settings *setting);
		static int xStepCount(Settings *settings);
    static double stepWidth(Settings *settings);
    static double stepHeight(Settings *settings);
};

#endif
