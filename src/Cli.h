#ifndef Cli_H
#define Cli_H
#include "Settings.h"
using namespace std;

class Cli {
  public:
    static void intro(Settings &settings);
    static bool openingQuestion(bool &firstPass);
    static void outro();
    static void setDisplaySize(Settings &settings);
    static void setEpsilon(Settings &settings);
    static vector<vector<double> > setPolynomials(Settings &settings);
    static void setWindow(Settings &settings);
    static bool yesno();
};

#endif
