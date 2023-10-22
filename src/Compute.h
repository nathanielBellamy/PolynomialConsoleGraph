#ifndef Compute_H
#define Compute_H
#include<vector>
#include "Settings.h"
using namespace std;

class Compute {

	public:
		static double execute(vector<double> polynomial, double x);
		static vector<vector<double> > computeImageArray(vector<vector<double> > polynomialArray, vector<vector<double> > imageArray, Settings settings);
	  static vector<double> piecewsieImage(vector<vector<double> > polynomialArray, Settings settings);
		static int minimumIndexWithinYPlusEpsilon(vector<double> imageOfX, double y, Settings settings);
};

#endif
