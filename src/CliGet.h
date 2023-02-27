#ifndef CliGet_H
#define CliGet_H

  class CliGet {
    // https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
    public:
      static double cliDouble();
      static int cliInt();
      static void ignoreLine();
      static bool cliyesno();
  };

#endif
