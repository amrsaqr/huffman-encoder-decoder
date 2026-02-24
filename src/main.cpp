// Copyright 2025 Amr Saqr

#include <iostream>
#include "args.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
  Args args;
  args.Read(argc - 1, argv + 1);
  cout << args.GetInputFile() << endl;
  cout << args.GetOutputFile() << endl;
  return 0;
}
