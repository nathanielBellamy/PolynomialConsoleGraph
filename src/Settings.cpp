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
  double Settings::stepWidth = 0;
  double Settings::stepHeight = 0;
  int Settings::xStepCount = 0;
  bool Settings::pieceWise = false;



