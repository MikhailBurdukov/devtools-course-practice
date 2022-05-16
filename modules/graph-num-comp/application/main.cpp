// Copyright 2022 Burdukov Mikhail
#include <iostream>

#include "include/api.h"

int main(int argc, const char** argv) {
  Num_of_components comp(argc, argv);
  std::cout << comp.get_result() << std::endl;
}
