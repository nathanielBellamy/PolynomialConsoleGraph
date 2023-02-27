#ifndef CliGet_H
#define CliGet_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

  class CliGet {
    // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
    public:
      static double cliDouble();
      static int cliInt();
      static void ignoreLine();
      static bool cliyesno();
  };

#endif
