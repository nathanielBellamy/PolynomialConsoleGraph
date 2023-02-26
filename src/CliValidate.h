#ifndef CliValidate_H
#define CliValidate_H
#include "Settings.h"
using namespace std;

class CliValidate {
  public:
    static bool axisInterval(float min, float max);
    static bool displaySize(int size);
    static bool epsilon(float epsilon);
    static bool maxDegree(int max);
    static bool polyCount(int count);
};

#endif
