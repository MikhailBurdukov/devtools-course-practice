// Copyright 2022 Burdukov Mikhail

#include "include/api.h"

#include <cstdlib>
#include <iostream>
Num_of_components::Num_of_components(int argc, const char** argv) {
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  size_t size = static_cast<size_t>(n);
  std::vector<std::vector<int>> G(size, std::vector<int>(size, 0));
  int current = 3;
  for (int i = 0; i < m; i++) {
    int x, y;
    x = atoi(argv[current++]);
    y = atoi(argv[current++]);
    G[x][y] = G[y][x] = 1;
  }
  graph = matrixType(n, G);
}

int Num_of_components::get_result() { return graph.numComp(0); }
