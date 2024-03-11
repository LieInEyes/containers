#ifndef CONTAINERS_SRC_BACKEND_RAW_MEMORY_DYNAMIC_H_
#define CONTAINERS_SRC_BACKEND_RAW_MEMORY_DYNAMIC_H_

#include <iostream>
#include <utility>

template <typename T>
class RawMemoryDynamic {
 public:
  RawMemoryDynamic();
  explicit RawMemoryDynamic(const size_t n);
  explicit RawMemoryDynamic(const RawMemoryDynamic &other) = delete;
  explicit RawMemoryDynamic(RawMemoryDynamic &&other) = delete;
  ~RawMemoryDynamic();

  T &operator=(const RawMemoryDynamic &other) = delete;
  T &operator=(RawMemoryDynamic &&other) noexcept = delete;

  static T *AllocateMem(const size_t &n);
  static void DeAllocateMem(T *buf);

  size_t GetCapacity() const;
  void SetCapacity(size_t i);
  T *GetArr();
  void SetArr(T *temp);

  T &operator[](size_t i);
  const T &operator[](size_t i) const;

  void Swap(RawMemoryDynamic &other);

 private:
  size_t m_capacity_;
  T *buf_;
};

template <typename T>
RawMemoryDynamic<T>::RawMemoryDynamic() : m_capacity_(0U), buf_(nullptr) {}

template <typename T>
RawMemoryDynamic<T>::RawMemoryDynamic(const size_t n)
    : m_capacity_(n), buf_(nullptr) {
  if (n) {
    buf_ = AllocateMem(n);
  }
}

template <typename T>
RawMemoryDynamic<T>::~RawMemoryDynamic() {
  DeAllocateMem(buf_);
}

template <typename T>
T *RawMemoryDynamic<T>::AllocateMem(const size_t &n) {
  return static_cast<T *>(operator new(sizeof(T) * n));
}

template <typename T>
void RawMemoryDynamic<T>::DeAllocateMem(T *buf) {
  operator delete(buf);
}

template <typename T>
size_t RawMemoryDynamic<T>::GetCapacity() const {
  return m_capacity_;
}

template <typename T>
void RawMemoryDynamic<T>::SetCapacity(size_t i) {
  m_capacity_ = i;
}

template <typename T>
T *RawMemoryDynamic<T>::GetArr() {
  return buf_;
}

template <typename T>
void RawMemoryDynamic<T>::SetArr(T *temp) {
  buf_ = temp;
}

template <typename T>
T &RawMemoryDynamic<T>::operator[](size_t i) {
  return buf_[i];
}

template <typename T>
const T &RawMemoryDynamic<T>::operator[](size_t i) const {
  return buf_[i];
}

template <typename T>
void RawMemoryDynamic<T>::Swap(RawMemoryDynamic &other) {
  std::swap(buf_, other.buf_);
  std::swap(m_capacity_, other.m_capacity_);
}

#endif  // CONTAINERS_SRC_BACKEND_RAW_MEMORY_DYNAMIC_H_
