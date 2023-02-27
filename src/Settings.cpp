#include<iostream>
#include "Settings.h"
using namespace std;

	char Settings::backgroundChar= '.';
	char Settings::originChar = '+';
	char Settings::xAxisChar = '-';
	char Settings::yAxisChar = '|';
	double Settings::xMin = -1.3;
	double Settings::xMax = 1.3;
	double Settings::yMin = -1.3;
	double Settings::yMax = 1.3;
	double Settings::epsilon = 0.1;
  int Settings::displayWidth = 80;
  int Settings::displayHeight = 30;

  double Settings::stepWidth(Settings settings) {
    return (settings.xMax - settings.xMin)/settings.displayWidth;
  }

  double Settings::stepHeight(Settings settings) {
    return (settings.yMax - settings.yMin)/settings.displayHeight;
  }

  int Settings::xStepCount(Settings settings) {
    double stepWidth = Settings::stepWidth(settings);
    return (xMax - xMin)/stepWidth;
  }



