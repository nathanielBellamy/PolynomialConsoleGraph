#ifndef Draw_H
#define Draw_H
#include<vector>
#include "Settings.h"
#include "../../Constants.h" // from nbsdsp repo containing this submodule
using namespace std;

class Draw {
	public:
		static std::string createRow(vector<vector<double> > imageArray, double y, Settings settings);
    static void createRowPiecewise(
      double (*image)[EQ_IMAGE_WIDTH], 
      int i, 
      Settings *settings,
      char (*graphNext)[EQ_IMAGE_HEIGHT][EQ_IMAGE_WIDTH]
    );
		static void render(vector<vector<double> > polynomialArray, Settings settings);
    static void renderPiecewise(vector<vector<double> > polynomialArray, Settings *settings);
		static char determineCharacterToRender(vector<double> imageOfX, double x, double y, Settings settings);
    static char determineCharacterToRenderPiecewise(
      double (*image)[EQ_IMAGE_WIDTH], 
      int t, 
      double x, 
      double y, 
      Settings *settings
    );
};

#endif
