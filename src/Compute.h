#ifndef Compute_H
#define Compute_H
#include<vector>
#include "Settings.h"
using namespace std;

class Compute {

	public:
		static float execute(vector<float> polynomial, float x);
		static vector<vector<float> > computeImageArray(vector<vector<float> > polynomialArray, vector<vector<float> > imageArray, Settings settings);
		static int minimumIndexWithinYPlusEpsilon(vector<float> imageOfX, float y, Settings settings);
};

#endif
