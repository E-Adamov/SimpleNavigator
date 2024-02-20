#ifndef A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_MATRIX_H_
#define A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_MATRIX_H_

#include <vector>
using namespace std;
namespace s21 {

class Matrix {
 public:
  Matrix() = default;
  Matrix(size_t rows, size_t cols);

  size_t getNumRows() const;
  size_t getNumColumns() const;
  double &operator()(int row, int col);
  double &operator()(int row, int col) const;
  void setSizeMatrix(size_t rows, size_t cols);
  void cleanMatrix();

 private:
  vector<vector<double>> matrix_;
};

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_MATRIX_H_
