#ifndef Cli_H
#define Cli_H
#include "Settings.h"
using namespace std;

class Cli {
  public:
    static void setDisplaySize(Settings &settings);
    static void setEpsilon(Settings &settings);
    static vector<vector<float> > setPolynomials(Settings &settings);
    static void setWindow(Settings &settings);
};

#endif
