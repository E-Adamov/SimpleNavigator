#ifndef A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_STACK_H_
#define A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_STACK_H_

#include <cstddef>

#include "s21_node_single.h"
namespace s21 {

template <typename T>
class Stack {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  typedef node_single<value_type> Node;

  Stack() = default;
  ~Stack();
  size_type size();
  bool empty();
  void stack();
  void push(const_reference value);
  value_type pop();
  const_reference top();
  bool find(value_type value);

 private:
  size_type size_{};
  Node *head_{};
  Node *tail_{};
};

template <typename T>
Stack<T>::~Stack() {
  while (size_ != 0) pop();
}

template <typename T>
std::size_t Stack<T>::size() {
  return size_;
}

template <typename T>
bool Stack<T>::empty() {
  return size_ == 0;
}

template <typename T>
void Stack<T>::stack() {
  size_ = 0;
}

template <typename T>
void Stack<T>::push(const_reference value) {
  if (size_ == 0) {
    Node *new_node = new Node(value);
    ++size_;
    head_ = tail_ = new_node;
    head_->next_ = nullptr;
  } else {
    Node *new_node = new Node(value);
    ++size_;
    new_node->next_ = head_;
    head_ = new_node;
  }
}

template <typename T>
T Stack<T>::pop() {
  value_type value{};
  if (!empty()) {
    Node *node_to_delete = head_;
    value = node_to_delete->data;
    head_ = head_->next_;
    delete node_to_delete;
    --size_;
  } else {
    throw std::invalid_argument("the stack is empty");
  }
  return value;
}

template <typename T>
const T &Stack<T>::top() {
  if (!empty()) {
    return head_->data;
  } else {
    throw std::invalid_argument("the stack is empty");
  }
}

template <typename T>
bool Stack<T>::find(value_type value) {
  Node *current_node = head_;
  for (int i = 0; i < size_; ++i) {
    if (current_node->data == value) {
      return true;
    } else {
      current_node = current_node->next_;
    }
  }
  return false;
}

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_STACK_H_
