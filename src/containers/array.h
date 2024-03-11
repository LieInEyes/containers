#ifndef CONTAINERS_SRC_CONTAINER_ARRAY_H
#define CONTAINERS_SRC_CONTAINER_ARRAY_H

#include <iostream>
#include <limits>
#include <utility>

namespace my_space {
template <typename T, size_t size>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Array() = default;
  explicit Array(std::initializer_list<value_type> const &items);
  Array(const Array &other);
  Array(Array &&other) noexcept;
  ~Array() = default;

  my_space::Array<T, size> &operator=(const Array &other);
  my_space::Array<T, size> &operator=(Array &&other) noexcept;

  reference At(size_type pos);
  reference operator[](size_type pos);
  const_reference Front() const;
  const_reference Back() const;
  iterator Data() noexcept;

  iterator Begin() noexcept;
  iterator End() noexcept;

  bool Empty() const noexcept;
  constexpr size_type Size();
  size_type MaxSize();

  void Swap(Array &other) noexcept;
  void Fill(const_reference value) noexcept;

 private:
  T buf_[size];
};
}  // namespace my_space

//// КОНСТРУКТОРЫ
template <typename T, size_t size>
my_space::Array<T, size>::Array(std::initializer_list<value_type> const &items) {
  size_t i = 0;
  for (auto it = items.begin(); it != items.end(); it++, ++i) {
    buf_[i] = T(*it);
  }
  for (; i < size; ++i) {
    buf_[i] = T();
  }
}

template <typename T, size_t size>
my_space::Array<T, size>::Array(const Array &other) {
  for (size_t i = 0; i != size; ++i) {
    buf_[i] = other.buf_[i];
  }
}

template <typename T, size_t size>
my_space::Array<T, size>::Array(Array &&other) noexcept {
  *this = other;
}

//// ПЕРЕГРУЗКА ОПЕРАТОРА =
template <typename T, size_t size>
my_space::Array<T, size> &my_space::Array<T, size>::operator=(const Array &other) {
  Array<T, size> temp(other);
  Swap(temp);
  return *this;
}

template <typename T, size_t size>
my_space::Array<T, size> &my_space::Array<T, size>::operator=(Array &&other) noexcept {
  *this = other;
  return *this;
}

//// ДОСТУП К ЭЛЕМЕНТАМ ВЕКТОРА
template <typename T, size_t size>
typename my_space::Array<T, size>::reference my_space::Array<T, size>::At(size_type pos) {
  if (pos >= size) {
    throw std::out_of_range(
        "Error: the specified position is out of bounds of the written "
        "elements");
  }
  return buf_[pos];
}

template <typename T, size_t size>
typename my_space::Array<T, size>::reference my_space::Array<T, size>::operator[](
    size_type pos) {
  return buf_[pos];
}

template <typename T, size_t size>
typename my_space::Array<T, size>::const_reference my_space::Array<T, size>::Front()
    const {
  return buf_[0];
}

template <typename T, size_t size>
typename my_space::Array<T, size>::const_reference my_space::Array<T, size>::Back()
    const {
  return size ? buf_[size - 1] : buf_[0];
}

template <typename T, size_t size>
T *my_space::Array<T, size>::Data() noexcept {
  return buf_;
}

//// ИТЕРАТОРЫ
template <typename T, size_t size>
typename my_space::Array<T, size>::iterator my_space::Array<T, size>::Begin() noexcept {
  return buf_;
}

template <typename T, size_t size>
typename my_space::Array<T, size>::iterator my_space::Array<T, size>::End() noexcept {
  return !size ? buf_ : buf_ + size;
}

//// МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИЕ КОНТЕЙНЕРА
template <typename T, size_t size>
bool my_space::Array<T, size>::Empty() const noexcept {
  return size ? false : true;
}

template <typename T, const size_t size>
constexpr typename my_space::Array<T, size>::size_type my_space::Array<T, size>::Size() {
  return size;
}

template <typename T, size_t size>
size_t my_space::Array<T, size>::MaxSize() {
  return size;
}

//// ДОСТУП КЭЛЕМЕНТАМ
template <typename T, size_t size>
void my_space::Array<T, size>::Swap(Array<T, size> &other) noexcept {
  std::swap(this->buf_, other.buf_);
}

template <typename T, size_t size>
void my_space::Array<T, size>::Fill(const_reference value) noexcept {
  for (size_t i = 0; i < size; ++i) {
    buf_[i] = T(value);
  }
}

#endif  // CONTAINERS_SRC_CONTAINER_ARRAY_H
