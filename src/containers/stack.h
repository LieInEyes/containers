#ifndef CONTAINERS_SRC_CONTAINER_STACK_H
#define CONTAINERS_SRC_CONTAINER_STACK_H

#include <iostream>

#include "../containers.h"

namespace my_space {

using namespace BackendListNode;

template <typename T>
class Stack : protected my_space::List<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Stack();
  explicit Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &other);
  Stack(Stack &&other) noexcept;
  ~Stack() = default;

  my_space::Stack<T> &operator=(const Stack &other);
  my_space::Stack<T> &operator=(Stack<T> &&other) noexcept;

  const_reference Top();

  bool Empty() const noexcept override;
  size_type Size() const override;

  void Push(const_reference value);
  void Pop();
  void Swap(Stack &other);

  template <typename... Args>
  void EmplaceFront(Args &&...args);
};
}  // namespace my_space

template <typename T>
my_space::Stack<T>::Stack() : List<T>() {}

template <typename T>
my_space::Stack<T>::Stack(std::initializer_list<value_type> const &items)
    : List<T>(items) {}

template <typename T>
my_space::Stack<T>::Stack(const Stack &other) : List<T>(other) {}

template <typename T>
my_space::Stack<T>::Stack(Stack &&other) noexcept : List<T>(std::move(other)) {}

//// ПЕРЕГРУЗКА ОПЕРАТОРА =
template <typename T>
my_space::Stack<T> &my_space::Stack<T>::operator=(const Stack &other) {
  List<T>::operator=(other);
  return *this;
}

template <typename T>
my_space::Stack<T> &my_space::Stack<T>::operator=(Stack<T> &&other) noexcept {
  List<T>::operator=(std::move(other));
  return *this;
}

//// ДОСТУП К ЭЛЕМЕНТАМ КОНТЕЙНЕРА
template <typename T>
typename my_space::Stack<T>::const_reference my_space::Stack<T>::Top() {
  return this->node_finish_->GetInfo();
}

//// МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИЕ КОНТЕЙНЕРА
template <typename T>
bool my_space::Stack<T>::Empty() const noexcept {
  return List<T>::Empty();
}

template <typename T>
typename my_space::Stack<T>::size_type my_space::Stack<T>::Size() const {
  return List<T>::Size();
}

//// ДОСТУП ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА
template <typename T>
void my_space::Stack<T>::Push(const_reference value) {
  List<T>::PushBack(value);
}

template <typename T>
void my_space::Stack<T>::Pop() {
  List<T>::PopBack();
}

template <typename T>
void my_space::Stack<T>::Swap(Stack &other) {
  List<T>::Swap(other);
}

template <typename T>
template <typename... Args>
void my_space::Stack<T>::EmplaceFront(Args &&...args) {
  List<T>::EmplaceBack(args...);
}

#endif  // CONTAINERS_SRC_CONTAINER_STACK_H
