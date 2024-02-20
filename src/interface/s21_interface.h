#ifndef A2_SIMPLENAVIGATOR_SRC_INTERFACE_S21_INTERFACE_H_
#define A2_SIMPLENAVIGATOR_SRC_INTERFACE_S21_INTERFACE_H_

#include <cstdlib>
#include <iostream>

#include "../graph/s21_graph.h"
#include "../graph/s21_graph_algorithms.h"
using namespace std;
namespace s21 {
class Interface {
 public:
  Interface(){};
  void start();

 private:
  s21::Graph graph_;
  void clearScreen();
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_INTERFACE_S21_INTERFACE_H_
