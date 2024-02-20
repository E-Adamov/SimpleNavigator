#include "./graph/s21_graph.h"
#include "./graph/s21_graph_algorithms.h"
#include <gtest/gtest.h>
// https://programforyou.ru/graph-redactor

TEST(loadGraphFromFile, test_1) {
  s21::Graph graph;
  double test[6][6] = {{0, 6, 3, 12, 0, 0}, {6, 0, 5, 0, 10, 0},
                       {3, 5, 0, 0, 0, 11}, {12, 0, 0, 0, 8, 7},
                       {0, 10, 0, 8, 0, 9}, {0, 0, 11, 7, 9, 0}};
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  EXPECT_EQ(graph.getSize(), 6);
  for (size_t r = 0; r < graph.getSize(); ++r) {
    for (size_t c = 0; c < graph.getSize(); ++c) {
      EXPECT_EQ(graph(r, c), test[r][c]);
    }
  }
}
TEST(exportGraphToDot, invalid_arguments) {
  s21::Graph graph{};
  EXPECT_THROW(graph.exportGraphToDot("qwerty"), std::out_of_range);
  EXPECT_THROW(graph.loadGraphFromFile("ytrewq"), std::invalid_argument);
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  EXPECT_THROW(graph.exportGraphToDot("../qwerty/qwert"),
               std::invalid_argument);
}
TEST(exportGraphToDot, test_1) {
  s21::Graph graph{};

  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  graph.exportGraphToDot("test_export_not_orient.dot");
}
TEST(exportGraphToDot, test_2) {
  s21::Graph graph{};
  graph.loadGraphFromFile("graph_txt/test_6_orient.txt");
  graph.exportGraphToDot("test_export_orient.dot");
}
TEST(breadthFirstSearch, graph_empty) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_no_graph.txt");
  EXPECT_THROW(ga.breadthFirstSearch(graph, 1), std::out_of_range);
}
TEST(breadthFirstSearch, invalid_arguments) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_graph.txt");
  EXPECT_THROW(ga.breadthFirstSearch(graph, graph.getSize() + 1),
               std::invalid_argument);
  EXPECT_THROW(ga.breadthFirstSearch(graph, 0), std::invalid_argument);
  EXPECT_THROW(ga.breadthFirstSearch(graph, -1), std::invalid_argument);
}
TEST(breadthFirstSearch, test_1) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  std::vector<int> result1 = {4, 1, 5, 6, 2, 3};
  EXPECT_EQ(result1, ga.breadthFirstSearch(graph, 4));
  std::vector<int> result2 = {5, 2, 4, 6, 1, 3};
  EXPECT_EQ(result2, ga.breadthFirstSearch(graph, 5));
  std::vector<int> result3 = {6, 3, 4, 5, 1, 2};
  EXPECT_EQ(result3, ga.breadthFirstSearch(graph, 6));
}
TEST(breadthFirstSearch, test_2) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_orient.txt");
  std::vector<int> result4 = {4, 6, 3, 5, 2, 1};
  EXPECT_EQ(result4, ga.breadthFirstSearch(graph, 4));
  std::vector<int> result5 = {5, 2, 4, 1, 6, 3};
  EXPECT_EQ(result5, ga.breadthFirstSearch(graph, 5));
  std::vector<int> result6 = {6, 3, 5, 2, 4, 1};
  EXPECT_EQ(result6, ga.breadthFirstSearch(graph, 6));
}
TEST(depthFirstSearch, graph_empty) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_no_graph.txt");
  EXPECT_THROW(ga.depthFirstSearch(graph, 1), std::out_of_range);
}
TEST(depthFirstSearch, invalid_arguments) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_graph.txt");
  EXPECT_THROW(ga.depthFirstSearch(graph, graph.getSize() + 1),
               std::invalid_argument);
  EXPECT_THROW(ga.depthFirstSearch(graph, 0), std::invalid_argument);
  EXPECT_THROW(ga.depthFirstSearch(graph, -1), std::invalid_argument);
}
TEST(depthFirstSearch, test_1) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  std::vector<int> result1 = {1, 2, 3, 6, 4, 5};
  EXPECT_EQ(result1, ga.depthFirstSearch(graph, 1));
  std::vector<int> result2 = {3, 1, 2, 5, 4, 6};
  EXPECT_EQ(result2, ga.depthFirstSearch(graph, 3));
  std::vector<int> result3 = {5, 2, 1, 3, 6, 4};
  EXPECT_EQ(result3, ga.depthFirstSearch(graph, 5));
}
TEST(depthFirstSearch, test_2) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_orient.txt");
  std::vector<int> result4 = {1, 3, 2, 4, 6, 5};
  EXPECT_EQ(result4, ga.depthFirstSearch(graph, 1));
  std::vector<int> result5 = {3, 2, 1, 4, 6, 5};
  EXPECT_EQ(result5, ga.depthFirstSearch(graph, 3));
  std::vector<int> result6 = {5, 2, 1, 3, 4, 6};
  EXPECT_EQ(result6, ga.depthFirstSearch(graph, 5));
}
TEST(getShortestPathBetweenVertices, graph_empty) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_no_graph.txt");
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, 1, 2),
               std::out_of_range);
}
TEST(getShortestPathBetweenVertices, invalid_arguments) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_graph.txt");
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, graph.getSize() + 1, 1),
               std::invalid_argument);
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, 0, 1),
               std::invalid_argument);
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, -1, 1),
               std::invalid_argument);
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, 1, graph.getSize() + 1),
               std::invalid_argument);
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, 1, 0),
               std::invalid_argument);
  EXPECT_THROW(ga.getShortestPathBetweenVertices(graph, 1, -1),
               std::invalid_argument);
}
TEST(getShortestPathBetweenVertices, test_1) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  int result1{14};
  EXPECT_EQ(result1, ga.getShortestPathBetweenVertices(graph, 1, 6));
  int result2{15};
  EXPECT_EQ(result2, ga.getShortestPathBetweenVertices(graph, 3, 4));
  int result3{16};
  EXPECT_EQ(result3, ga.getShortestPathBetweenVertices(graph, 5, 1));
}
TEST(getShortestPathBetweenVertices, test_2) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_orient.txt");
  int result4{19};
  EXPECT_EQ(result4, ga.getShortestPathBetweenVertices(graph, 1, 6));
  int result5{23};
  EXPECT_EQ(result5, ga.getShortestPathBetweenVertices(graph, 3, 4));
  int result6{16};
  EXPECT_EQ(result6, ga.getShortestPathBetweenVertices(graph, 5, 1));
}
TEST(getShortestPathsBetweenAllVertices, graph_empty) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_no_graph.txt");
  EXPECT_THROW(ga.getShortestPathsBetweenAllVertices(graph), std::out_of_range);
}
TEST(getShortestPathsBetweenAllVertices, test_1) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  auto result1 = ga.getShortestPathsBetweenAllVertices(graph);
  for (size_t r = 0; r < graph.getSize(); ++r) {
    for (size_t c = 0; c < graph.getSize(); ++c) {
      auto test = ga.getShortestPathBetweenVertices(graph, r + 1, c + 1);
      EXPECT_EQ(result1(r, c), test);
    }
  }
}
  TEST(getShortestPathsBetweenAllVertices, test_2) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_orient.txt");
  auto result2 = ga.getShortestPathsBetweenAllVertices(graph);
  for (size_t r = 0; r < graph.getSize(); ++r) {
    for (size_t c = 0; c < graph.getSize(); ++c) {
      auto test = ga.getShortestPathBetweenVertices(graph, r + 1, c + 1);
      EXPECT_EQ(result2(r, c), test);
    }
  }
}
TEST(getLeastSpanningTree, graph_empty) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_no_graph.txt");
  EXPECT_THROW(ga.getLeastSpanningTree(graph), std::out_of_range);
}
TEST(getLeastSpanningTree, invalid_arguments) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_disconnected.txt");
  EXPECT_THROW(ga.getLeastSpanningTree(graph), std::runtime_error);
}
TEST(getLeastSpanningTree, test_1) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  double test[6][6] = {{0, 0, 3, 0, 0, 0},  {0, 0, 5, 0, 10, 0},
                       {3, 5, 0, 0, 0, 0},  {0, 0, 0, 0, 8, 7},
                       {0, 10, 0, 8, 0, 0}, {0, 0, 0, 7, 0, 0}};

  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  auto result = ga.getLeastSpanningTree(graph);
  for (size_t r = 0; r < graph.getSize(); ++r) {
    for (size_t c = 0; c < graph.getSize(); ++c) {
      EXPECT_EQ(result(r, c), test[r][c]);
    }
  }
}
TEST(solveTravelingSalesmanProblem, graph_empty) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_no_graph.txt");
  EXPECT_THROW(ga.solveTravelingSalesmanProblem(graph), std::out_of_range);
}
TEST(solveTravelingSalesmanProblem, invalid_arguments) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_disconnected.txt");
  EXPECT_THROW(ga.solveTravelingSalesmanProblem(graph), std::runtime_error);
}
TEST(solveTravelingSalesmanProblem, test_1) {
  s21::Graph graph;
  s21::GraphAlgorithms ga;
  graph.loadGraphFromFile("graph_txt/test_6_not_orient.txt");
  auto result = ga.solveTravelingSalesmanProblem(graph);
  EXPECT_EQ(45, result.distance);
  EXPECT_EQ(7, result.vertices.size());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}