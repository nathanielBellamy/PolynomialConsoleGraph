#include<iostream>
#include "Settings.h"
using namespace std;

	char Settings::backgroundChar= '.';
	char Settings::originChar = '+';
	char Settings::xAxisChar = '-';
	char Settings::yAxisChar = '|';
	float Settings::xMin = -1.3;
	float Settings::xMax = 1.3;
	float Settings::yMin = -1.3;
	float Settings::yMax = 1.3;
	float Settings::epsilon = 0.1;
  int Settings::displayWidth = 80;
  int Settings::displayHeight = 30;

  float Settings::stepWidth(Settings settings)
  {
    return (settings.xMax - settings.xMin)/settings.displayWidth;
  }

  float Settings::stepHeight(Settings settings)
  {
    return (settings.yMax - settings.yMin)/settings.displayHeight;
  }

  int Settings::xStepCount(Settings settings)
  {
    float stepWidth = Settings::stepWidth(settings);
    return (xMax - xMin)/stepWidth;
  }



