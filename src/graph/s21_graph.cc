#include "s21_graph.h"

void s21::Graph::loadGraphFromFile(string filename) {
  ifstream in(filename);
  if (!in.is_open()) {
    throw std::invalid_argument("Такого файла не существует");
  }
  in >> size_;
  matrix_ = s21::Matrix(size_, size_);
  for (size_t r = 0; r < size_; ++r) {
    for (size_t c = 0; c < size_; ++c) {
      in >> matrix_(r, c);
    }
  }
}

void s21::Graph::exportGraphToDot(string filename) {
  if (empty()) {
    throw std::out_of_range("Граф пустой");
  }
  ofstream out(filename);
  if (!out.is_open()) {
    throw std::invalid_argument("Такого файла не существует");
  }
  if (out.is_open() && !empty()) {
    out << "graph graphname {\n";
    for (size_t r = 0; r < matrix_.getNumRows(); ++r) {
      out << "    " << r + 1 << ";\n";
    }

    bool orient_graph{false};
    for (size_t r = 0; r < matrix_.getNumRows(); ++r) {
      for (size_t c = 0; c < matrix_.getNumColumns(); ++c) {
        if (matrix_(r, c) != matrix_(c, r)) orient_graph = true;
      }
    }

    for (size_t r = 0; r < matrix_.getNumRows(); ++r) {
      for (size_t c = 0; c < matrix_.getNumColumns(); ++c) {
        if (!orient_graph && c >= r && matrix_(r, c) != 0) {
          out << "    " << r + 1 << " -- " << c + 1 << ";\n";
        } else if (orient_graph && matrix_(r, c) != 0) {
          out << "    " << r + 1 << " -> " << c + 1 << ";\n";
        }
      }
    }
    out << "}\n";
    out.close();
  }
}

double &s21::Graph::operator()(size_t row, size_t col) const {
  return const_cast<double &>(matrix_(row, col));
}

size_t s21::Graph::getSize() const { return size_; }

double &s21::Graph::operator()(size_t row, size_t col) {
  return matrix_(row, col);
}

bool s21::Graph::empty() { return size_ == 0 ? true : false; }
