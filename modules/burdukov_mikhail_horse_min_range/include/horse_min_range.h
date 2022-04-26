// Copyright 2022 Burdukov Mikhail

#ifndef MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_HORSE_MIN_RANGE_H_
#define MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_HORSE_MIN_RANGE_H_

#include <utility>
#include <vector>

struct chess_position_t {
  char i;
  int16_t j;
  std::pair<int16_t, int16_t> convert_to_pair() const {
    return std::pair<int16_t, int16_t>(i - 'a', j - 1);
  }
  chess_position_t(char a, int16_t b) : i(a), j(b) {}
};

class minHorseRange {
 private:
  std::vector<std::vector<int16_t>> table;
  std::pair<int16_t, int16_t> start, finish;
  const size_t table_size = 8;
  const std::vector<int16_t> di = {2, 2, 1, 1, -2, -2, -1, -1};
  const std::vector<int16_t> dj = {1, -1, 2, -2, 1, -1, 2, -2};

 public:
  minHorseRange()
      : start(std::pair<int16_t, int16_t>(1, 1)),
        finish(std::pair<int16_t, int16_t>(1, 1)) {
    table.assign(table_size, std::vector<int16_t>(table_size, 0));
  }

  minHorseRange(chess_position_t s, chess_position_t f)
      : start(s.convert_to_pair()), finish(f.convert_to_pair()) {
    table.assign(table_size, std::vector<int16_t>(table_size, 0));
  }
  void set_barrier(const chess_position_t& pos) {
    auto conv = pos.convert_to_pair();
    table[conv.first][conv.second] = 1;
  }
  void set_start(const chess_position_t& pos) { start = pos.convert_to_pair(); }
  void set_finish(const chess_position_t& pos) {
    finish = pos.convert_to_pair();
  }
  void set_table(const std::vector<std::vector<int16_t>> _t) { table = _t; }
  int8_t calc_range() const;
};

#endif  // MODULES_BURDUKOV_MIKHAIL_HORSE_MIN_RANGE_INCLUDE_HORSE_MIN_RANGE_H_
