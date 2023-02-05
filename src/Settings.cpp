#include<iostream>
#include "Settings.h"
using namespace std;

	char Settings::_backgroundChar= '.';

	char Settings::_originChar = '+';
	char Settings::_xAxisChar = '-';
	char Settings::_yAxisChar = '|';
	float Settings::_xMin = -1.3;
	float Settings::_xMax = 1.3;
	float Settings::_yMin = -1.3;
	float Settings::_yMax = 1.3;
	float Settings::_epsilon = 0.1;
	float Settings::_domainWidth = Settings::_xMax - Settings::_xMin;
	float Settings::_rangeHeight = Settings::_yMax - Settings::_yMin;

	int Settings::_displayWidth = 40;
	int Settings::_displayHeight = 15;

	float Settings::_stepWidth = Settings::_domainWidth/Settings::_displayWidth;
	float Settings::_stepHeight = Settings::_rangeHeight/Settings::_displayHeight;

	int Settings::_xStepCount = (Settings::_xMax - Settings::_xMin) / Settings::_stepWidth;



