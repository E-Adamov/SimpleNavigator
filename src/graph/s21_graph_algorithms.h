#ifndef A2_SIMPLENAVIGATOR_SRC_GRAPH_S21_GRAPH_ALGORITHMS_H_
#define A2_SIMPLENAVIGATOR_SRC_GRAPH_S21_GRAPH_ALGORITHMS_H_

#include <algorithm>  // для std::find
#include <fstream>
#include <vector>

#include "../containers/s21_matrix.h"
#include "../containers/s21_queue.h"
#include "../containers/s21_stack.h"
#include "s21_ant_colony.h"
#include "s21_graph.h"
using namespace std;
namespace s21 {

class GraphAlgorithms {
 public:
  vector<int> depthFirstSearch(s21::Graph &graph, size_t startVertex);
  vector<int> breadthFirstSearch(s21::Graph &graph, size_t startVertex);
  int getShortestPathBetweenVertices(Graph &graph, size_t vertex1,
                                     size_t vertex2);
  s21::Matrix getShortestPathsBetweenAllVertices(Graph &graph);
  s21::Matrix getLeastSpanningTree(Graph &graph);
  s21::TsmResult solveTravelingSalesmanProblem(Graph &graph);

 private:
  const int kInf = 1e9;
  auto findValue(const vector<int> &data, int value) -> bool;
  void shiftVector(vector<int> &vector);
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_GRAPH_S21_GRAPH_ALGORITHMS_H_
