#ifndef A2_SIMPLENAVIGATOR_SRC_GRAPH_S21_GRAPH_H_
#define A2_SIMPLENAVIGATOR_SRC_GRAPH_S21_GRAPH_H_
// https://programforyou.ru/graph-redactor

#include <fstream>
#include <iostream>

#include "../containers/s21_matrix.h"
using namespace std;
namespace s21 {

class Graph {
 public:
  Graph() = default;
  void loadGraphFromFile(string filename);
  void exportGraphToDot(string filename);
  size_t getSize() const;
  bool empty();
  double &operator()(size_t row, size_t col);
  double &operator()(size_t row, size_t col) const;

 private:
  s21::Matrix matrix_;
  size_t size_{};
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_GRAPH_S21_GRAPH_H_
