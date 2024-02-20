#ifndef A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_NOD_SINGLE_H_
#define A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_NOD_SINGLE_H_

namespace s21 {
template <typename T>
class node_single {
 public:
  T data;
  node_single *next_;

  node_single() : data(0), next_(nullptr) {}
  explicit node_single(T val) : data(val), next_(nullptr) {}
};
}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_NOD_SINGLE_H_
