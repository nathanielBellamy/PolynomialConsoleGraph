#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Draw.h"
#include "Compute.h"
#include "Settings.h"
using namespace std;

  std::string Draw::createRow(vector<vector<double> > imageArray, double y, Settings settings) 
  {
		double x;
		std::string row = " ";

    double stepWidth = Compute::stepWidth(&settings);
		for (int t = 0;  t < settings.displayWidth; t++) 
    {
			x = (t * stepWidth) + settings.xMin;
			vector<double> imageOfX(imageArray.size(), 0);
			for (int k = 0; k < imageArray.size(); k++) 
      {
				imageOfX.at(k) = imageArray.at(k).at(t);
			}
			row += determineCharacterToRender(imageOfX, x, y, settings);
		}
		return row + " \r\n";
	};
  
  void Draw::createRowPiecewise(
    double (*image)[64], 
    int rowIndex, 
    Settings *settings,
    char (*graphNext)[32][64]
  )
  {
    double x;
    double y;
    int idx = settings->displayHeight - rowIndex - 1;
		y = ((double) idx * settings->stepHeight) + settings->yMin;
    for (int j = 0; j < 64; j++) // column
    {
      // printf("\n immm %f", (*image)[j]);
      x = (j * settings->stepWidth) + settings->xMin;
      (*graphNext)[rowIndex][j] = determineCharacterToRenderPiecewise(image, j, x, y, settings);
    }
  }

  void Draw::render(vector<vector<double> > polynomialArray, Settings settings) 
  {
		Compute compute;
		double y;
		std::string margin = " ";
		std::string output;

    int xStepCount = settings.xStepCount;
    vector<double> imageOfZeroFunction(xStepCount+1, 0);
		vector<vector<double> > imageArray(polynomialArray.size(), imageOfZeroFunction);

		imageArray = compute.computeImageArray(polynomialArray, imageArray, settings);
		
    double stepHeight = Compute::stepHeight(&settings);
		for (int s = settings.displayHeight; s > -1; s--) {
			y = (s * stepHeight) + settings.yMin;
			std::cout << createRow(imageArray, y, settings);
		}
	};

  // void Draw::renderPiecewise(vector<vector<double> > polynomialArray, Settings *settings) 
  // {
		// double y;
		// std::string margin = " ";
		// std::string output;

		// vector<double> image;
		// image = Compute::piecewiseImage(polynomialArray, settings);
		// 
		// for (int j = settings->displayHeight; s > -1; s--) {
		// 	y = (s * settings->stepHeight) + settings->yMin;
  //     // TODO:
  //     //   - store the result
  //     //   - update changes
		// 	std::cout << createRowPiecewise(image, y, settings);
		// }
  // }

  char Draw::determineCharacterToRender(vector<double> imageOfX, double x, double y, Settings settings) 
  {
		Compute compute;
    double stepWidth = settings.stepWidth; 
    double stepHeight = settings.stepHeight;
		for (int i = 0; i < imageOfX.size(); i++) {
			char backgroundChar = settings.backgroundChar;
			int indexToPrint;
      indexToPrint = compute.minimumIndexWithinYPlusEpsilon(imageOfX, y, &settings);
			
      if (indexToPrint > -1) 
      {
				return '0' + indexToPrint;
			}
      else 
      {
				if (abs(y) < stepHeight/2) 
        {
					if (abs(x) < stepWidth/2) 
          {
						backgroundChar = settings.originChar;
					}
					else 
          {
						backgroundChar = settings.xAxisChar;
					}
				}
				else 
        {
					if (abs(x) < stepWidth/2) 
          {
						backgroundChar = settings.yAxisChar;
					}
				}
				return backgroundChar;
			}
		}	
		return settings.backgroundChar;
	};

  char Draw::determineCharacterToRenderPiecewise(double (*image)[64], int j, double x, double y, Settings *settings) 
  {
    // printf("\nim: %f", (*image)[j]);
    // printf("\ny: %f", y);
    // printf("\n === \n");
    if ( Compute::withinEpsilon_a(image, j, y, settings) ) 
    {
      return '#';
    }
    else if ((*image)[j] < y)
    {
      return 'o';
    }
    else 
    {
      char backgroundChar = settings->backgroundChar;
      if (abs(y) < settings->stepHeight/2) 
      {
        if (abs(x) < settings->stepWidth/2) 
        {
          backgroundChar = settings->originChar;
        }
        else 
        {
          backgroundChar = settings->xAxisChar;
        }
      }
      else 
      {
        if (abs(x) < settings->stepWidth/2) 
        {
          backgroundChar = settings->yAxisChar;
        }
      }
      return backgroundChar;
    }
  };
