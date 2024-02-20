#ifndef A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_QUEUE_H_
#define A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_QUEUE_H_

#include <cstddef>

#include "s21_node_single.h"
namespace s21 {

template <typename T>
class Queue {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  typedef node_single<value_type> Node;

  Queue() = default;
  ~Queue();
  size_type size();
  bool empty();
  void queue();
  void push(const_reference value);
  value_type pop();
  const_reference front();
  const_reference back();
  bool find(value_type value);

 private:
  size_type size_{};
  Node *head_{};
  Node *tail_{};
};

template <typename T>
Queue<T>::~Queue() {
  while (size_ != 0) pop();
}

template <typename T>
std::size_t Queue<T>::size() {
  return size_;
}

template <typename T>
bool Queue<T>::empty() {
  return size_ == 0;
}

template <typename T>
void Queue<T>::queue() {
  size_ = 0;
}

template <typename T>
void Queue<T>::push(const_reference value) {
  if (size_ == 0) {
    Node *new_node = new Node(value);
    ++size_;
    head_ = tail_ = new_node;
    head_->next_ = nullptr;
  } else {
    Node *new_node = new Node(value);
    ++size_;
    tail_->next_ = new_node;
    new_node->next_ = nullptr;
    tail_ = new_node;
  }
}

template <typename T>
T Queue<T>::pop() {
  value_type value{};
  if (!empty()) {
    Node *node_to_delete = head_;
    value = node_to_delete->data;
    head_ = head_->next_;
    delete node_to_delete;
    --size_;
  } else {
    throw std::invalid_argument("the queue is empty");
  }
  return value;
}

template <typename T>
const T &Queue<T>::front() {
  if (!empty()) {
    return head_->data;
  } else {
    throw std::invalid_argument("the queue is empty");
  }
}

template <typename T>
const T &Queue<T>::back() {
  if (!empty()) {
    return tail_->data;
  } else {
    throw std::invalid_argument("the queue is empty");
  }
}

template <typename T>
bool Queue<T>::find(value_type value) {
  Node *current_node = head_;
  for (size_t i = 0; i < size_; ++i) {
    if (current_node->data == value) {
      return true;
    } else {
      current_node = current_node->next_;
    }
  }
  return false;
}

}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_CONTAINERS_S21_
