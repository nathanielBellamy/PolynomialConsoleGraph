#include<iostream>
#include<string>
#include<vector>
#include "CliGet.h"
using namespace std;
  // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
  // TODO: use template to dry this out
  double CliGet::cliDouble() {
    while (true) { // Loop until user enters a valid input
      double x{};
      std::cin >> x;

      if (!std::cin) {// has a previous extraction failed?
          // handle failure
          std::cin.clear(); // put back in 'normal' operation mode
          ignoreLine(); // remove the bad input
          std::cerr << "Oops, that input is invalid.  Please try again.\n";
      } else {
          ignoreLine(); // remove any extraneous input
          return x;
      }
    }
  }

  int CliGet::cliInt() {
    while (true) {
      int x{};
      std::cin >> x;

      if (!std::cin) {
        std::cin.clear();
        ignoreLine();
        std::cerr << "Oops, that input is invalid.  Please try again.\n";
      } else {
          ignoreLine(); // remove any extraneous input
          return x;
      }
    }
  }

  bool CliGet::cliyesno() {
    while (true) { // Loop until user enters a valid input
      std::cout << "...[y]es or [n]o... ";
      char x{};
      std::cin >> x;

    
      if (!std::cin || (x != 'y' && x != 'n')) {
        std::cin.clear();
        ignoreLine(); // remove the bad input
        std::cerr << "Oops, that input is invalid.  Please try again.\n";
      } else {
          ignoreLine(); // remove any extraneous input
          return x == 'y';
      }
    }
  }

  void CliGet::ignoreLine() {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
