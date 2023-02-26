#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Cli.h"
#include "Draw.h"
#include "Settings.h"
using namespace std;

int main (){
  Cli cli;
	Draw draw;
  Settings settings;

  cli.intro(settings);
  bool firstPass;
  firstPass = true;

Start:
  bool graphPolynomials;
  graphPolynomials = cli.openingQuestion(firstPass);

	if (!graphPolynomials) {
		cli.outro();
		return 0;
	}

  vector<vector<float> > polynomialArray;
  polynomialArray = cli.setPolynomials(settings);
  cli.setWindow(settings);
  cli.setDisplaySize(settings);
  cli.setEpsilon(settings);

	std::cout << "Ok. Here we go! \r\n";
	draw.render(polynomialArray, settings);

	goto Start;

	return 0;
};
