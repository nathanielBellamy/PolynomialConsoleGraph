#ifndef Draw_H
#define Draw_H
#include<vector>
#include "Settings.h"
using namespace std;

class Draw {
	public:
		static std::string createRow(vector<vector<float> > imageArray, float y, Settings settings);
		static void render(vector<vector<float> > polynomialArray, Settings settings);
		static char determineCharacterToRender(vector<float> imageOfX, float x, float y, Settings settings);
};

#endif
