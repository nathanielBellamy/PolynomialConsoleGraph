#include<iostream>
#include<string>
#include<vector>
#include "Cli.h"
#include "CliValidate.h"
using namespace std;

  bool CliValidate::displaySize(int size) {
    bool result;
    result = true;
    if (size < 1) {
      result = false;
      std::cout << "Please enter a whole number greater than or equal to 1. \n";
    }
    return result;
  };

  bool CliValidate::epsilon(float epsilon) {
    bool result;
    result = true;
    if (epsilon <= 0) {
      result = false;
      std::cout << "Please enter a number greater than 0. \n";
    }
    return result;
  };
