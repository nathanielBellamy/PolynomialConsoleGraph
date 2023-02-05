#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Draw.h"
#include "Compute.h"
#include "Settings.h"
using namespace std;



std::string Draw::createRow(vector<vector<float> > imageArray, float y)
	{
		Settings settings;
		float x;
		std::string row = " ";

		for (int t = 0;  t < settings._displayWidth; t++)
		{
			x = (t * settings._stepWidth) + settings._xMin;
			vector<float> imageOfX(imageArray.size(), 0);
			for (int k = 0; k < imageArray.size(); k++)
			{
				imageOfX.at(k) = imageArray.at(k).at(t);
			}
			row += determineCharacterToRender(imageOfX, x, y);
		}
		return row + " \r\n";
	};

void Draw::render(vector<vector<float> > polynomialArray)
	{
		Settings settings;
		Compute compute;
		float y;
		std::string margin = " ";
		std::string output;

		vector<float> imageOfZeroFunction(settings._xStepCount+1, 0);
		vector<vector<float> > imageArray(polynomialArray.size(), imageOfZeroFunction);

		imageArray = compute.computeImageArray(polynomialArray, imageArray);
		
		for (int s = settings._displayHeight; s > -1; s--)
		{
			y = (s * settings._stepHeight) + settings._yMin;
			std::cout << createRow(imageArray, y);
		}
	};

char Draw::determineCharacterToRender(vector<float> imageOfX, float x, float y)
	{
		Settings settings;
		Compute compute;
		for (int i = 0; i < imageOfX.size(); i++)
		{
			char backgroundChar = settings._backgroundChar;
			int indexToPrint = compute.minimumIndexWithinYPlusEpsilon(imageOfX, y);
			if (indexToPrint > -1)
			{
				return '0' + indexToPrint;
			}
			else
			{
				if (abs(y) < settings._stepHeight/2)
				{
					if (abs(x) < settings._stepWidth/2)
					{
						backgroundChar = settings._originChar;
					}
					else
					{
						backgroundChar = settings._xAxisChar;
					}
				}
				else
				{
					if (abs(x) < settings._stepWidth/2)
					{
						backgroundChar = settings._yAxisChar;
					}
				}
				return backgroundChar;
			}
		}	
		return settings._backgroundChar;
	};