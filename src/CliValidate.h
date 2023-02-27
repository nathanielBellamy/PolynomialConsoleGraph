#ifndef CliValidate_H
#define CliValidate_H
#include "Settings.h"
using namespace std;

class CliValidate {
  public:
    static bool axisInterval(double min, double max);
    static bool displaySize(int size);
    static bool epsilon(double epsilon);
    static bool maxDegree(int max);
    static bool polyCount(int count);
};

#endif
