#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Draw.h"
#include "Compute.h"
#include "Settings.h"
using namespace std;

  std::string Draw::createRow(vector<vector<double> > imageArray, double y, Settings settings) {
		double x;
		std::string row = " ";

    double stepWidth = Settings::stepWidth(settings);
		for (int t = 0;  t < settings.displayWidth; t++) {
			x = (t * stepWidth) + settings.xMin;
			vector<double> imageOfX(imageArray.size(), 0);
			for (int k = 0; k < imageArray.size(); k++) {
				imageOfX.at(k) = imageArray.at(k).at(t);
			}
			row += determineCharacterToRender(imageOfX, x, y, settings);
		}
		return row + " \r\n";
	};

  void Draw::render(vector<vector<double> > polynomialArray, Settings settings) {
		Compute compute;
		double y;
		std::string margin = " ";
		std::string output;

    int xStepCount = Settings::xStepCount(settings);
		vector<double> imageOfZeroFunction(xStepCount+1, 0);
		vector<vector<double> > imageArray(polynomialArray.size(), imageOfZeroFunction);

		imageArray = compute.computeImageArray(polynomialArray, imageArray, settings);
		
    double stepHeight = Settings::stepHeight(settings);
		for (int s = settings.displayHeight; s > -1; s--) {
			y = (s * stepHeight) + settings.yMin;
			std::cout << createRow(imageArray, y, settings);
		}
	};

char Draw::determineCharacterToRender(vector<double> imageOfX, double x, double y, Settings settings) {
		Compute compute;
    double stepWidth = Settings::stepWidth(settings);
    double stepHeight = Settings::stepHeight(settings);
		for (int i = 0; i < imageOfX.size(); i++) {
			char backgroundChar = settings.backgroundChar;
			int indexToPrint = compute.minimumIndexWithinYPlusEpsilon(imageOfX, y, settings);
			if (indexToPrint > -1) {
				return '0' + indexToPrint;
			}
			else {
				if (abs(y) < stepHeight/2) {
					if (abs(x) < stepWidth/2) {
						backgroundChar = settings.originChar;
					}
					else {
						backgroundChar = settings.xAxisChar;
					}
				}
				else {
					if (abs(x) < stepWidth/2) {
						backgroundChar = settings.yAxisChar;
					}
				}
				return backgroundChar;
			}
		}	
		return settings.backgroundChar;
	};
