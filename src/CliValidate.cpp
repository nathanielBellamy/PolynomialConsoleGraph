#include<iostream>
#include<string>
#include<vector>
#include "Cli.h"
#include "CliValidate.h"
using namespace std;

  bool CliValidate::axisInterval(double min, double max) {
    bool result;
    result = true;
    if (max <= min) {
      result = false;
      std::cout << "Please ensure sure the min you enter is less than the max.";
    }
    return result;
  }

  bool CliValidate::displaySize(int size) {
    bool result;
    result = true;
    if (size < 1) {
      result = false;
      std::cout << "Please enter a whole number greater than or equal to 1. \n";
    }
    return result;
  };

  bool CliValidate::epsilon(double epsilon) {
    bool result;
    result = true;
    if (epsilon <= 0) {
      result = false;
      std::cout << "Please enter a number greater than 0. \n";
    }
    return result;
  };

  bool CliValidate::maxDegree(int max) {
    bool result;
    result = true;
    if (max < 0) {
      result = false;
      std::cout << "Please enter a non-negative whole number.";
    }
    return result;
  }

  bool CliValidate::polyCount(int count) {
    bool result;
    result = true;
    if (count < 1) {
      result = false;
      std::cout << "Please enter a number greater than or equal to 1.";
    }
    return result;
  }
