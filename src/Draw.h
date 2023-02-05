#ifndef Draw_H
#define Draw_H
#include<vector>
using namespace std;

class Draw {

	public:

		static std::string createRow(vector<vector<float> > imageArray, float y);

		static void render(vector<vector<float> > polynomialArray);

		static char determineCharacterToRender(vector<float> imageOfX, float x, float y);
};

#endif