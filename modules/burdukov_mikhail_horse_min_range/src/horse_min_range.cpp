// Copyright 2022 Burdukov Mikhail

#include "include/horse_min_range.h"

#include <queue>
#include <iostream>
int8_t minHorseRange::calc_range() const {
  const int8_t never_was = -1;
  std::vector<std::vector<int16_t>> was(
      table_size, std::vector<int16_t>(table_size, never_was));
  was[start.first][start.second] = 0;
  std::queue<std::pair<int16_t, int16_t>> q;
  q.push(start);
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    if (x == finish) break;
    for (size_t i = 0; i < di.size(); i++) {
      auto y(x);
      y.first += di[i];
      y.second += dj[i];
      if (y.first >= 0 && y.first < table_size && y.second >= 0 &&
          y.second < table_size && was[y.first][y.second] == never_was &&
          table[y.first][y.second] != 1) {
        was[y.first][y.second] = was[x.first][x.second] + 1;
        q.push(y);
      }
    }
  }
  return was[finish.first][finish.second];
}
