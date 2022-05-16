// Copyright 2022 Petrova Polina

#ifndef MODULES_GRAPH_NUM_COMP_INCLUDE_NUM_COMP_H_
#define MODULES_GRAPH_NUM_COMP_INCLUDE_NUM_COMP_H_

#include <random>
#include <vector>
#include <iostream>
int generateRandEdge();

class matrixType {
 private:
  int numVert;
  std::vector<std::vector<int> > Graph;
  std::vector<bool> used;

 public:
  explicit matrixType(int n);  // where n - num of vertex
  matrixType(int numVert, const std::vector<std::vector<int> >& G);
  int& operator()(int i, int j);
  int getNumVert();
  void DFS(int start, int f);
  int numComp(int f);
  matrixType(){ };
};
#endif  // MODULES_GRAPH_NUM_COMP_INCLUDE_NUM_COMP_H_
