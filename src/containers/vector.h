#ifndef CONTAINERS_SRC_CONTAINER_VECTOR_H
#define CONTAINERS_SRC_CONTAINER_VECTOR_H

#include <iostream>
#include <limits>
#include <utility>

#include "../backend/raw_memory_dynamic.h"

namespace my_space {
template <typename T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Vector();
  explicit Vector(size_type n);
  explicit Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &other);
  Vector(Vector &&other) noexcept;
  ~Vector();

  my_space::Vector<T> &operator=(const Vector &other);
  my_space::Vector<T> &operator=(Vector &&other) noexcept;

  reference At(size_type pos);
  reference operator[](size_type pos);
  const_reference Front() const;
  const_reference Back() const;
  T *Data() noexcept;

  iterator Begin() noexcept;
  iterator End() noexcept;

  bool Empty() const noexcept;
  size_type Size() const;
  size_type MaxSize() const;
  void Reserve(size_type size);
  size_type Capacity() const;
  void ShrinkToFit();

  void Clear();
  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);
  void PushBack(const_reference value);
  void PopBack();

  template <typename... Args>
  void EmplaceBack(Args &&...args);
  template <typename... Args>
  iterator Emplace(const_iterator pos, Args &&...args);

  template <typename... Args>
  iterator EqualCapacitySizeForInsert(iterator pos, const_reference value);
  template <typename... Args>
  iterator NotEqualCapacitySizeForInsert(const_iterator pos,
                                         const_reference value);
  template <typename... Args>
  iterator EqualCapacitySizeForEmplace(const_iterator pos, Args &&...args);
  template <typename... Args>
  iterator NotEqualCapacitySizeForEmplace(const_iterator pos, Args &&...args);

 private:
  size_t m_size_;
  RawMemoryDynamic<T> arr_;

  static void Construct(void *buf);
  static void Construct(void *buf, const T &elem);
  static void Construct(void *buf, T &&elem) noexcept;
  template <typename... Args>
  static void Construct(void *buf, Args &&...args) noexcept;
  static void Destroy(T *buf);
};
}  // namespace my_space

template <typename T>
void my_space::Vector<T>::Construct(void *buf) {
  new (buf) T();
}

template <typename T>
void my_space::Vector<T>::Construct(void *buf, const T &elem) {
  new (buf) T(elem);
}

template <typename T>
void my_space::Vector<T>::Construct(void *buf, T &&elem) noexcept {
  new (buf) T(std::move(elem));
}

template <typename T>
template <typename... Args>
void my_space::Vector<T>::Construct(void *buf, Args &&...args) noexcept {
  new (buf) T(args...);
}

template <typename T>
void my_space::Vector<T>::Destroy(T *buf) {
  buf->~T();
}

//// КОНСТРУКТОРЫ
template <typename T>
my_space::Vector<T>::Vector() : m_size_(0U) {}

template <typename T>
my_space::Vector<T>::Vector(size_type n) : m_size_(n), arr_(n) {
  if (n) {
    for (size_t i = 0; i < n; ++i) {
      Construct(arr_.GetArr() + i);
    }
  }
}

template <typename T>
my_space::Vector<T>::Vector(std::initializer_list<value_type> const &items)
    : m_size_(items.size()), arr_(items.size()) {
  iterator i = Begin();
  for (auto it = items.begin(); it != items.end(); it++, ++i) {
    Construct(i, *it);
  }
}

template <typename T>
my_space::Vector<T>::Vector(const Vector &other) : arr_(other.arr_.GetCapacity()) {
  for (size_t i = 0; i != other.m_size_; ++i) {
    Construct(arr_.GetArr() + i, other.arr_[i]);
  }
  m_size_ = other.m_size_;
}

template <typename T>
my_space::Vector<T>::Vector(Vector &&other) noexcept : m_size_(other.m_size_) {
  arr_.Swap(other.arr_);
  other.arr_.SetArr(nullptr);
  other.m_size_ = 0;
}

template <typename T>
my_space::Vector<T>::~Vector() {
  if (arr_.GetArr()) {
    for (size_t i = 0; i != m_size_; ++i) {
      Destroy(arr_.GetArr() + i);
    }
  }
}

//// ПЕРЕГРУЗКА ОПЕРАТОРА =
template <typename T>
my_space::Vector<T> &my_space::Vector<T>::operator=(const Vector &other) {
  if (arr_.GetCapacity() < other.arr_.GetCapacity()) {
    for (size_t i = 0; i != m_size_; ++i) {
      Destroy(arr_.GetArr() + i);
    }
    arr_.DeAllocateMem(arr_.GetArr());
    arr_.SetArr(arr_.AllocateMem(other.arr_.GetCapacity()));
    arr_.SetCapacity(other.arr_.GetCapacity());
  } else {
    for (size_t i = 0; i != m_size_; ++i) {
      Destroy(arr_.GetArr() + i);
    }
  }
  for (size_t i = 0; i != other.m_size_; ++i) {
    Construct(arr_.GetArr() + i, other.arr_[i]);
  }
  m_size_ = other.m_size_;
  return *this;
}

template <typename T>
my_space::Vector<T> &my_space::Vector<T>::operator=(Vector &&other) noexcept {
  for (size_t i = 0; i != m_size_; ++i) {
    Destroy(arr_.GetArr() + i);
  }
  if (arr_.GetArr() != other.arr_.GetArr()) {
    m_size_ = other.m_size_;
    arr_.Swap(other.arr_);
    other.arr_.DeAllocateMem(other.arr_.GetArr());
    other.arr_.SetArr(nullptr);
    other.m_size_ = 0;
    other.arr_.SetCapacity(0);
  }
  return *this;
}

//// ДОСТУП К ЭЛЕМЕНТАМ ВЕКТОРА
template <typename T>
typename my_space::Vector<T>::reference my_space::Vector<T>::At(size_type pos) {
  if (pos >= m_size_) {
    throw std::out_of_range(
        "Error: the specified position is out of bounds of the written "
        "elements");
  }
  return arr_.GetArr()[pos];
}

template <typename T>
typename my_space::Vector<T>::reference my_space::Vector<T>::operator[](size_type pos) {
  return arr_[pos];
}

template <typename T>
typename my_space::Vector<T>::const_reference my_space::Vector<T>::Front() const {
  return arr_[0];
}

template <typename T>
typename my_space::Vector<T>::const_reference my_space::Vector<T>::Back() const {
  return arr_[m_size_ - 1];
}

template <typename T>
T *my_space::Vector<T>::Data() noexcept {
  return arr_.GetArr();
}

//// ИТЕРАТОРЫ
template <typename T>
typename my_space::Vector<T>::iterator my_space::Vector<T>::Begin() noexcept {
  return arr_.GetArr();
}

template <typename T>
typename my_space::Vector<T>::iterator my_space::Vector<T>::End() noexcept {
  return !m_size_ ? arr_.GetArr() : arr_.GetArr() + m_size_;
}

//// МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИЕ КОНТЕЙНЕРА
template <typename T>
bool my_space::Vector<T>::Empty() const noexcept {
  return m_size_ ? false : true;
}

template <typename T>
typename my_space::Vector<T>::size_type my_space::Vector<T>::Size() const {
  return m_size_;
}

template <typename T>
size_t my_space::Vector<T>::MaxSize() const {
  return std::numeric_limits<size_t>::max() / sizeof(T) / 2;
}

template <typename T>
void my_space::Vector<T>::Reserve(size_type size) {
  if (size > this->MaxSize()) {
    throw std::length_error(
        "Error: the amount of allocated memory must be greater than the number "
        "of elements written to the vector");
  }
  if (size > arr_.GetCapacity()) {
    RawMemoryDynamic<T> arr2(size);
    for (size_t i = 0; i != m_size_; ++i) {
      Construct(arr2.GetArr() + i, arr_[i]);
    }
    for (size_t i = 0; i != m_size_; ++i) {
      Destroy(arr_.GetArr() + i);
    }
    arr_.Swap(arr2);
  }
}

template <typename T>
typename my_space::Vector<T>::size_type my_space::Vector<T>::Capacity() const {
  return arr_.GetCapacity();
}

template <typename T>
void my_space::Vector<T>::ShrinkToFit() {
  if (arr_.GetCapacity() > m_size_) {
    RawMemoryDynamic<T> arr2(m_size_);
    for (size_t i = 0; i < m_size_; ++i) {
      Construct(arr2.GetArr() + i, arr_[i]);
    }
    arr_.Swap(arr2);
  }
}

//// ДОСТУП ДЛЯ ИЗМЕНЕНИЯ ВЕКТОРА
template <typename T>
void my_space::Vector<T>::Clear() {
  m_size_ = 0;
}

template <typename T>
typename my_space::Vector<T>::iterator my_space::Vector<T>::Insert(
    iterator pos, const_reference value) {
  if (pos < Begin() || pos >= Begin() + arr_.GetCapacity() * 2 ||
      pos - (Begin() + m_size_) > 0) {
    throw std::out_of_range(
        "Error: the specified position is out of bounds of the written "
        "elements");
  }
  T *result;
  if (arr_.GetCapacity() == m_size_) {
    result = EqualCapacitySizeForInsert(pos, value);
  } else {
    result = NotEqualCapacitySizeForInsert(pos, value);
  }
  ++m_size_;
  return result;
}

template <typename T>
void my_space::Vector<T>::Erase(iterator pos) {
  if (pos < End()) {
    T *temp = pos;
    for (; temp < (End() - 1); ++temp) {
      *temp = *(temp + 1);
    }
  }
  --m_size_;
}

template <typename T>
void my_space::Vector<T>::PushBack(const_reference value) {
  if (m_size_ == arr_.GetCapacity()) {
    Reserve(m_size_ == 0 ? 1 : m_size_ * 2);
  }
  Construct(End(), value);
  ++m_size_;
}

template <typename T>
void my_space::Vector<T>::PopBack() {
  Destroy(End() - 1);
  --m_size_;
}

//// БОНУСЫ
template <typename T>
template <typename... Args>
void my_space::Vector<T>::EmplaceBack(Args &&...args) {
  if (m_size_ == arr_.GetCapacity()) {
    Reserve(m_size_ == 0 ? 1 : m_size_ * 2);
  }
  Construct(arr_.GetArr() + m_size_, args...);
  ++m_size_;
}

template <typename T>
template <typename... Args>
typename my_space::Vector<T>::iterator my_space::Vector<T>::Emplace(const_iterator pos,
                                                          Args &&...args) {
  T *result;
  if (arr_.GetCapacity() == m_size_) {
    result = EqualCapacitySizeForEmplace(pos, args...);
  } else {
    result = NotEqualCapacitySizeForEmplace(pos, args...);
  }
  ++m_size_;
  return result;
}

//// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
template <typename T>
template <typename... Args>
typename my_space::Vector<T>::iterator my_space::Vector<T>::EqualCapacitySizeForInsert(
    iterator pos, const_reference value) {
  T *result = nullptr;
  RawMemoryDynamic<T> arr2(arr_.GetCapacity() ? arr_.GetCapacity() * 2 : 1);
  T *temp = arr_.GetArr();
  T *temp2 = arr2.GetArr();
  for (; temp2 < arr2.GetArr() + m_size_ + 1; ++temp, ++temp2) {
    if (temp == pos) {
      result = temp2;
      Construct(temp2, value);
      ++temp2;
      if (temp >= End()) {
        Construct(temp2, value);
      } else {
        Construct(temp2, *temp);
      }
    } else if (temp < arr_.GetArr() + m_size_) {
      Construct(temp2, *temp);
    } else {
      Construct(temp2);
    }
  }
  arr_.Swap(arr2);
  return result;
}

template <typename T>
template <typename... Args>
typename my_space::Vector<T>::iterator my_space::Vector<T>::NotEqualCapacitySizeForInsert(
    const_iterator pos, const_reference value) {
  T *result = nullptr;
  T *temp = End();
  for (; temp > pos; --temp) {
    Construct(temp, *(temp - 1));
  }
  result = temp;
  Construct(temp, value);
  return result;
}

template <typename T>
template <typename... Args>
typename my_space::Vector<T>::iterator my_space::Vector<T>::EqualCapacitySizeForEmplace(
    const_iterator pos, Args &&...args) {
  T *result = nullptr;
  RawMemoryDynamic<T> arr2(arr_.GetCapacity() ? arr_.GetCapacity() * 2 : 1);
  T *temp = arr_.GetArr();
  T *temp2 = arr2.GetArr();
  for (; temp2 < arr2.GetArr() + m_size_ + 1; ++temp, ++temp2) {
    if (temp == pos) {
      result = temp2;
      Construct(temp2, args...);
      ++temp2;
      if (temp >= End()) {
        Construct(temp2, args...);
      } else {
        Construct(temp2, *temp);
      }
    } else if (temp < arr_.GetArr() + m_size_) {
      Construct(temp2, *temp);
    } else {
      Construct(temp2);
    }
  }
  arr_.Swap(arr2);
  return result;
}

template <typename T>
template <typename... Args>
typename my_space::Vector<T>::iterator
my_space::Vector<T>::NotEqualCapacitySizeForEmplace(const_iterator pos,
                                               Args &&...args) {
  T *result = nullptr;
  T *temp = End();
  for (; temp > pos; --temp) {
    Construct(temp, *(temp - 1));
  }
  result = temp;
  Construct(temp, args...);
  return result;
}

#endif  // CONTAINERS_SRC_CONTAINER_VECTOR_H
