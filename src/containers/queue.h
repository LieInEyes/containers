#ifndef CONTAINERS_SRC_CONTAINER_QUEUE_H
#define CONTAINERS_SRC_CONTAINER_QUEUE_H

#include <iostream>

#include "../containers.h"

namespace my_space {

using namespace BackendListNode;

template <typename T>
class Queue : protected my_space::List<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Queue();
  explicit Queue(std::initializer_list<value_type> const &items);
  Queue(const Queue &other);
  Queue(Queue &&other) noexcept;
  ~Queue() = default;

  my_space::Queue<T> &operator=(const Queue &other);
  my_space::Queue<T> &operator=(Queue<T> &&other) noexcept;

  const_reference Front();
  const_reference Back();

  bool Empty() const noexcept override;
  size_type Size() const override;

  void Push(const_reference value);
  void Pop();
  void Swap(Queue &other);

  template <typename... Args>
  void EmplaceBack(Args &&...args);
};
}  // namespace my_space

template <typename T>
my_space::Queue<T>::Queue() : List<T>() {}

template <typename T>
my_space::Queue<T>::Queue(std::initializer_list<value_type> const &items)
    : List<T>(items) {}

template <typename T>
my_space::Queue<T>::Queue(const Queue &other) : List<T>(other) {}

template <typename T>
my_space::Queue<T>::Queue(Queue &&other) noexcept : List<T>(std::move(other)) {}

//// ПЕРЕГРУЗКА ОПЕРАТОРА =
template <typename T>
my_space::Queue<T> &my_space::Queue<T>::operator=(const Queue &other) {
  List<T>::operator=(other);
  return *this;
}

template <typename T>
my_space::Queue<T> &my_space::Queue<T>::operator=(Queue<T> &&other) noexcept {
  List<T>::operator=(std::move(other));
  return *this;
}

//// ДОСТУП К ЭЛЕМЕНТАМ КОНТЕЙНЕРА
template <typename T>
typename my_space::Queue<T>::const_reference my_space::Queue<T>::Front() {
  return List<T>::Front();
}

template <typename T>
typename my_space::Queue<T>::const_reference my_space::Queue<T>::Back() {
  return List<T>::Back();
}

//// МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИЕ КОНТЕЙНЕРА
template <typename T>
bool my_space::Queue<T>::Empty() const noexcept {
  return my_space::List<T>::Empty();
}

template <typename T>
typename my_space::Queue<T>::size_type my_space::Queue<T>::Size() const {
  return List<T>::Size();
}

//// ДОСТУП ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА
template <typename T>
void my_space::Queue<T>::Push(const_reference value) {
  List<T>::PushBack(value);
}

template <typename T>
void my_space::Queue<T>::Pop() {
  List<T>::PopFront();
}

template <typename T>
void my_space::Queue<T>::Swap(Queue &other) {
  List<T>::Swap(other);
}

template <typename T>
template <typename... Args>
void my_space::Queue<T>::EmplaceBack(Args &&...args) {
  List<T>::EmplaceBack(args...);
}

#endif  // CONTAINERS_SRC_CONTAINER_QUEUE_H
