#include "s21_graph_algorithms.h"

vector<int> s21::GraphAlgorithms::depthFirstSearch(Graph &graph,
                                                   size_t startVertex) {
  size_t shift_vertex = startVertex - 1;
  if (graph.empty()) throw out_of_range("Граф пустой");
  if (!(shift_vertex < graph.getSize()))
    throw invalid_argument("Вершина неверная");
  vector<int> visit;
  s21::Stack<int> stack;
  stack.stack();
  stack.push(shift_vertex);
  while (!stack.empty()) {
    int vertex = stack.top();
    stack.pop();
    if (!findValue(visit, vertex)) {
      visit.push_back(vertex);
      for (auto i = graph.getSize() - 1; i + 1 > 0; --i) {
        if (graph(vertex, i) && !findValue(visit, i)) {
          stack.push(i);
        }
      }
    }
  }
  shiftVector(visit);
  return visit;
}

vector<int> s21::GraphAlgorithms::breadthFirstSearch(Graph &graph,
                                                     size_t startVertex) {
  size_t shift_vertex = startVertex - 1;
  if (graph.empty()) throw out_of_range("Граф пустой");
  if (!(shift_vertex < graph.getSize()))
    throw invalid_argument("Вершина неверная");
  vector<int> visit;
  s21::Queue<int> queue;
  queue.queue();
  queue.push(shift_vertex);
  while (!queue.empty()) {
    int vertex = queue.front();
    queue.pop();
    if (!findValue(visit, vertex)) {
      visit.push_back(vertex);
      for (size_t i = 0; i < graph.getSize(); ++i) {
        if (graph(vertex, i) && !findValue(visit, i) && !queue.find(i)) {
          queue.push(i);
        }
      }
    }
  }
  shiftVector(visit);
  return visit;
}

int s21::GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph,
                                                         size_t vertex1,
                                                         size_t vertex2) {
  size_t shift_vertex1 = vertex1 - 1;
  size_t shift_vertex2 = vertex2 - 1;
  if (graph.empty()) throw out_of_range("Граф пустой");
  if (!(shift_vertex1 < graph.getSize()))
    throw invalid_argument("Первая вершина неверная");
  if (!(shift_vertex2 < graph.getSize()))
    throw invalid_argument("Вторая вершина неверная");

  vector<int> distance(graph.getSize(), kInf);
  vector<int> visit(graph.getSize(), false);
  distance[shift_vertex1] = 0;
  for (size_t i = 0; i < graph.getSize(); ++i) {
    int current_vertex{};
    bool flag{false};
    // поиск текущей вершины с минимальной дистанцией из непосещенных
    for (size_t k = 0; k < distance.size(); ++k) {
      if (!visit[k] && flag == false) {
        current_vertex = k;
        flag = true;
      } else if (!visit[k] && distance[k] < distance[current_vertex]) {
        current_vertex = k;
      }
    }
    visit[current_vertex] = true;
    for (size_t j = 0; j < graph.getSize(); ++j) {
      if (graph(current_vertex, j)) {
        distance[j] = min(distance[j], distance[current_vertex] +
                                           (int)graph(current_vertex, j));
      }
    }
  }
  return distance[shift_vertex2];
}

s21::Matrix s21::GraphAlgorithms::getShortestPathsBetweenAllVertices(
    Graph &graph) {
  if (graph.empty()) throw out_of_range("Граф пустой");

  s21::Matrix result(graph.getSize(), graph.getSize());
  for (size_t i = 0; i < graph.getSize(); ++i) {
    for (size_t j = 0; j < graph.getSize(); ++j) {
      if (graph(i, j) == 0 && i != j) {
        result(i, j) = kInf;
      } else if (i == j) {
        result(i, j) = 0;
      } else {
        result(i, j) = graph(i, j);
      }
    }
  }

  for (size_t k = 0; k < graph.getSize(); ++k) {
    for (size_t i = 0; i < graph.getSize(); ++i) {
      for (size_t j = 0; j < graph.getSize(); ++j) {
        if (result(i, k) < kInf && result(k, j) < kInf) {
          result(i, j) = min(result(i, j), result(i, k) + result(k, j));
        }
      }
    }
  }

  return result;
}

s21::Matrix s21::GraphAlgorithms::getLeastSpanningTree(Graph &graph) {
  if (graph.empty()) throw out_of_range("Граф пустой");
  if (breadthFirstSearch(graph, 1).size() != (size_t)graph.getSize())
    throw runtime_error(
        "Граф не является связным, нельзя построить "
        "минимальное остовное дерево");

  s21::Matrix result(graph.getSize(), graph.getSize());
  result.cleanMatrix();
  size_t count_add_edge{0};
  vector<bool> visit(graph.getSize());
  visit[0] = true;
  while (count_add_edge < graph.getSize() - 1) {
    int min = kInf;
    int x{0}, y{0};
    for (size_t i = 0; i < graph.getSize(); ++i) {
      if (visit[i]) {
        for (size_t j = 0; j < graph.getSize(); ++j) {
          if (!visit[j] && graph(i, j)) {
            if (min > graph(i, j)) {
              min = graph(i, j);
              x = i;
              y = j;
            }
          }
        }
      }
    }
    result(x, y) = graph(x, y);
    result(y, x) = graph(x, y);
    visit[y] = true;
    ++count_add_edge;
  }
  return result;
}

s21::TsmResult s21::GraphAlgorithms::solveTravelingSalesmanProblem(
    s21::Graph &graph) {
  if (graph.empty()) throw out_of_range("Граф пустой");
  s21::AntColony ac;
  s21::TsmResult result;
  result = ac.findPath(graph);
  if (result.distance == INFINITY)
    throw runtime_error("Невозможно найти решение");
  shiftVector(result.vertices);
  return result;
}

bool s21::GraphAlgorithms::findValue(const vector<int> &data, int value) {
  auto result{find(begin(data), end(data), value)};
  if (result == end(data))
    return false;
  else
    return true;
}

void s21::GraphAlgorithms::shiftVector(vector<int> &vector) {
  for (size_t i = 0; i < vector.size(); ++i) {
    vector[i] = vector[i] + 1;
  }
}
