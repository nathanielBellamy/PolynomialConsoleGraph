#ifndef Draw_H
#define Draw_H
#include<vector>
#include "Settings.h"
using namespace std;

class Draw {
	public:
		static std::string createRow(vector<vector<double> > imageArray, double y, Settings settings);
		static void render(vector<vector<double> > polynomialArray, Settings settings);
		static char determineCharacterToRender(vector<double> imageOfX, double x, double y, Settings settings);
};

#endif
