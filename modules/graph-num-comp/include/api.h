// Copyright 2022 Burdukov Mikhail

#ifndef MODULES_GRAPH_NUM_COMP_INCLUDE_API_H_
#define MODULES_GRAPH_NUM_COMP_INCLUDE_API_H_

#include "include\num_comp.h" //NOLINT

class Num_of_components {
 private:
  matrixType graph;

 public:
  Num_of_components() {}
  Num_of_components(int argc, const char** argv);
  int get_result();
};

#endif  // MODULES_GRAPH_NUM_COMP_INCLUDE_API_H_
