#ifndef Draw_H
#define Draw_H
#include<vector>
#include "Settings.h"
using namespace std;

class Draw {
	public:
		static std::string createRow(vector<vector<double> > imageArray, double y, Settings settings);
    static void createRowPiecewise(
      float *, 
      int i, 
      Settings *settings,
      char (*graphNext)[30][80]
    );
		static void render(vector<vector<double> > polynomialArray, Settings settings);
    static void renderPiecewise(vector<vector<double> > polynomialArray, Settings *settings);
		static char determineCharacterToRender(vector<double> imageOfX, double x, double y, Settings settings);
    static char determineCharacterToRenderPiecewise(
      float *image, 
      int t, 
      double x, 
      double y, 
      Settings *settings
    );
};

#endif
