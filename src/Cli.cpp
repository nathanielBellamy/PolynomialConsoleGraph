#include<iostream>
#include<string>
#include "Cli.h"
#include "Settings.h"
using namespace std;

  void Cli::setEpsilon(Settings &settings)
  {
    char adjustEpsilon;
    std::cout << "============"
      << "Adjust Epsilon? (y/n) - "
      << "If you are having trouble seeing your graph, try increasing this value.";
    std::cin >> adjustEpsilon;

    if (adjustEpsilon == 'y')
    {
      int epsilon;
      std::cout << "Set Epsilon: ";
      std::cin >> epsilon;
      settings.epsilon = epsilon;
    }
  };
