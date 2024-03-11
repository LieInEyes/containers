#ifndef CONTAINERS_SRC_CONTAINER_LIST_H
#define CONTAINERS_SRC_CONTAINER_LIST_H

#include <iostream>
#include <limits>

#include "../backend/node.h"

namespace my_space {
using namespace BackendListNode;
template <typename T>
class List {
 public:
  class ListConstIterator;
  class ListIterator {
   public:
    ListIterator() : pos_(nullptr) {}
    explicit ListIterator(Node<T> *node) : pos_(node) {}
    ListIterator(const ListIterator &other) : pos_(other.pos_) {}
    ListIterator(ListIterator &&other) noexcept : pos_(std::move(other.pos_)) {}
    ~ListIterator() = default;

    //// перегрузка = ListIterator
    ListIterator &operator=(const ListIterator &other) {
      return ListIterator(other);
    }
    ListIterator &operator=(ListIterator &&other) noexcept {
      return ListIterator(std::move(other));
    }

    //// перегрузка префиксный инкримент/дикремент ListIterator
    ListIterator &operator++() {
      pos_ = pos_->GetNext();
      return *this;
    }

    ListIterator &operator--() {
      pos_ = pos_->GetPrev();
      return *this;
    }

    //// перегрузка постфиксный инкремент/дикремент ListIterator
    const ListIterator operator++(int) {
      ListIterator iter(*this);
      ++(*this);
      return iter;
    }

    const ListIterator operator--(int) {
      ListIterator iter(*this);
      --(*this);
      return iter;
    }

    //// перегрузка == != ListIterator
    bool operator==(const ListIterator &other) const {
      return pos_ == other.pos_;
    }

    bool operator==(const ListConstIterator &other) const {
      return pos_ == other.GetPos();
    }

    bool operator!=(const ListIterator &other) const {
      return pos_ != other.pos_;
    }

    bool operator!=(const ListConstIterator &other) const {
      return pos_ != other.GetPos();
    }

    //// перегрузка * -> ListIterator
    T &operator*() { return pos_->GetInfo(); }
    T *operator->() { return &pos_->GetInfo(); }

    Node<T> *GetPos() { return pos_; }

   private:
    Node<T> *pos_;
  };

  class ListConstIterator {
   public:
    ListConstIterator() : pos_(nullptr) {}
    explicit ListConstIterator(const Node<T> *node) : pos_(node) {}
    ListConstIterator(const ListConstIterator &other) : pos_(other.pos_) {}
    explicit ListConstIterator(ListIterator &&other) noexcept
        : pos_(std::move(other.pos_)) {}
    ~ListConstIterator() = default;

    //// перегрузка = ListConstIterator
    ListConstIterator &operator=(const ListConstIterator &other) {
      return ListConstIterator(other);
    };
    ListConstIterator &operator=(ListConstIterator &&other) noexcept {
      return ListConstIterator(std::move(other));
    };

    //// перегрузка префиксный инкримент/дикремент ListConstIterator
    ListConstIterator &operator++() {
      pos_ = pos_->GetNext();
      return *this;
    }

    ListConstIterator &operator--() {
      pos_ = pos_->GetPrev();
      return *this;
    }

    //// перегрузка постфиксный инкремент/дикремент ListConstIterator
    const ListConstIterator operator++(int) {
      ListConstIterator iter(*this);
      ++(*this);
      return iter;
    }

    const ListConstIterator operator--(int) {
      ListConstIterator iter(*this);
      --(*this);
      return iter;
    }

    //// перегрузка == != ListConstIterator
    bool operator==(const ListConstIterator &other) const {
      return pos_ == other.pos_;
    }

    bool operator==(ListIterator &other) const {
      return pos_ == other.GetPos();
    }

    bool operator!=(const ListConstIterator &other) const {
      return pos_ != other.pos_;
    }

    bool operator!=(ListIterator &other) const {
      return pos_ != other.GetPos();
    }

    //// перегрузка * -> ListConstIterator
    T operator*() const { return pos_->GetInfo(); }
    T *operator->() { return &pos_->GetInfo(); }

    const Node<T> *GetPos() const { return pos_; }

   private:
    const Node<T> *pos_;
  };

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = size_t;

  List();
  explicit List(size_type n);
  explicit List(std::initializer_list<value_type> const &items);
  List(const List &other);
  List(List &&other) noexcept;
  ~List();

  my_space::List<T> &operator=(const List &l);
  my_space::List<T> &operator=(List &&l) noexcept;

  const_reference Front() const;
  const_reference Back() const;

  iterator Begin() noexcept;
  iterator End() noexcept;

  const_iterator CBegin() const noexcept;
  const_iterator CEnd() const noexcept;

  virtual bool Empty() const noexcept;
  virtual size_type Size() const;
  virtual size_type MaxSize() const;

  void Clear();
  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);
  void PushBack(const_reference value);
  void PopBack();
  void PushFront(const_reference value);
  void PopFront();
  void Swap(List &other);
  void Merge(List &other);
  void Splice(const_iterator pos, List &other);
  void Reverse();
  void Unique();
  void Sort();

  template <typename... Args>
  void EmplaceBack(Args &&...args);

  template <typename... Args>
  void EmplaceFront(Args &&...args);

  template <typename... Args>
  iterator Emplace(const_iterator pos, Args &&...args);

 protected:
  size_t m_size_;
  Node<T> *node_start_;
  Node<T> *node_finish_;
  Node<T> *node_end_;
};
}  // namespace my_space

template <typename T>
my_space::List<T>::List()
    : m_size_(0U),
      node_start_(nullptr),
      node_finish_(nullptr),
      node_end_(new Node<T>) {
  node_end_->SetNext(node_start_);
  node_end_->SetPrev(node_finish_);
}

template <typename T>
my_space::List<T>::List(size_type n)
    : m_size_(0U),
      node_start_(nullptr),
      node_finish_(nullptr),
      node_end_(new Node<T>) {
  node_end_->SetNext(node_start_);
  node_end_->SetPrev(node_finish_);
  for (size_t i = 0; i < n; ++i) {
    PushBack(T());
  }
}

template <typename T>
my_space::List<T>::List(std::initializer_list<value_type> const &items)
    : m_size_(0U),
      node_start_(nullptr),
      node_finish_(nullptr),
      node_end_(new Node<T>) {
  node_end_->SetNext(node_start_);
  node_end_->SetPrev(node_finish_);
  for (auto it = items.begin(); it != items.end(); ++it) {
    PushBack(*it);
  }
}

template <typename T>
my_space::List<T>::List(const List &other)
    : m_size_(0U),
      node_start_(nullptr),
      node_finish_(nullptr),
      node_end_(new Node<T>) {
  node_end_->SetNext(node_start_);
  node_end_->SetPrev(node_finish_);
  *this = other;
}

template <typename T>
my_space::List<T>::List(List &&other) noexcept
    : m_size_(0U),
      node_start_(nullptr),
      node_finish_(nullptr),
      node_end_(new Node<T>) {
  node_end_->SetNext(node_start_);
  node_end_->SetPrev(node_finish_);
  *this = std::move(other);
}

template <typename T>
my_space::List<T>::~List() {
  Clear();
  delete node_end_;
}

//// ПЕРЕГРУЗКА ОПЕРАТОРА =
template <typename T>
my_space::List<T> &my_space::List<T>::operator=(const List &other) {
  if (this != &other) {
    Clear();
    m_size_ = 0;
    auto iter = other.node_start_;
    for (size_t i = 0; i < other.m_size_; ++i) {
      PushBack(iter->GetInfo());
      iter = iter->GetNext();
    }
  }
  return *this;
}

template <typename T>
my_space::List<T> &my_space::List<T>::operator=(List<T> &&other) noexcept {
  if (this != &other) {
    Clear();
    delete node_end_;
    m_size_ = other.m_size_;
    node_start_ = other.node_start_;
    node_finish_ = other.node_finish_;
    node_end_ = other.node_end_;
    other.m_size_ = 0;
    other.node_start_ = other.node_finish_ = other.node_end_ = nullptr;
  }
  return *this;
}

//// ДОСТУП К ЭЛЕМЕНТАМ КОНТЕЙНЕРА
template <typename T>
typename my_space::List<T>::const_reference my_space::List<T>::Front() const {
  return node_start_->GetInfo();
}

template <typename T>
typename my_space::List<T>::const_reference my_space::List<T>::Back() const {
  return node_finish_->GetInfo();
}

//// ИТЕРАТОРЫ
template <typename T>
typename my_space::List<T>::iterator my_space::List<T>::Begin() noexcept {
  iterator iter(node_start_);
  return iter;
}

template <typename T>
typename my_space::List<T>::iterator my_space::List<T>::End() noexcept {
  return m_size_ ? iterator(node_end_) : iterator(node_finish_);
}

template <typename T>
typename my_space::List<T>::const_iterator my_space::List<T>::CBegin() const noexcept {
  return const_iterator(node_start_);
}

template <typename T>
typename my_space::List<T>::const_iterator my_space::List<T>::CEnd() const noexcept {
  return m_size_ ? const_iterator(node_end_) : const_iterator(node_finish_);
}

//// МЕТОДЫ ДЛЯ ДОСТУПА К ИНФОРМАЦИИ О НАПОЛНЕНИЕ КОНТЕЙНЕРА
template <typename T>
bool my_space::List<T>::Empty() const noexcept {
  return !m_size_;
}

template <typename T>
typename my_space::List<T>::size_type my_space::List<T>::Size() const {
  return m_size_;
}

template <typename T>
size_t my_space::List<T>::MaxSize() const {
  return std::numeric_limits<size_t>::max() / sizeof(Node<T>) / 2;
}

//// ДОСТУП ДЛЯ ИЗМЕНЕНИЯ КОНТЕЙНЕРА
template <typename T>
void my_space::List<T>::Clear() {
  while (m_size_) {
    PopFront();
  }
}

template <typename T>
typename my_space::List<T>::iterator my_space::List<T>::Insert(iterator pos,
                                                     const_reference value) {
  if (pos == Begin()) {
    PushFront(value);
    return Begin();
  } else if (pos == End()) {
    PushBack(value);
    return --End();
  } else {
    auto *temp = new Node<T>(value);
    temp->SetPrev(pos.GetPos()->GetPrev());
    temp->SetNext(pos.GetPos());
    pos.GetPos()->SetPrev(temp);
    ++m_size_;
    return iterator(--pos);
  }
}

template <typename T>
void my_space::List<T>::Erase(iterator pos) {
  auto iter_beck = End();
  --iter_beck;
  if (pos == Begin()) {
    PopFront();
  } else if (pos == iter_beck) {
    PopBack();
  } else {
    Node<T> *temp = pos.GetPos();
    auto iter_prev = pos;
    --iter_prev;
    auto iter_next = pos;
    ++iter_next;
    iter_prev.GetPos()->SetNext(iter_next.GetPos());
    iter_next.GetPos()->SetPrev(iter_prev.GetPos());
    delete temp;
    --m_size_;
  }
}

template <typename T>
void my_space::List<T>::PushBack(const_reference value) {
  if (m_size_) {
    auto *temp = new Node<T>(value);
    temp->SetPrev(node_finish_);
    node_finish_ = temp;
    node_finish_->SetNext(node_end_);
    node_end_->SetPrev(node_finish_);
  } else {
    node_start_ = new Node<T>(value);
    node_finish_ = node_start_;
    node_finish_->SetNext(node_end_);
    node_end_->SetPrev(node_finish_);
    node_end_->SetNext(node_start_);
    node_start_->SetPrev(node_end_);
  }
  ++m_size_;
}

template <typename T>
void my_space::List<T>::PopBack() {
  auto *temp = node_finish_;
  if (m_size_ > 1) {
    node_finish_ = node_finish_->GetPrev();
    node_finish_->SetNext(node_end_);
    delete temp;
  } else {
    node_finish_ = node_start_ = node_end_;
    node_end_->SetNext(nullptr);
    node_end_->SetPrev(nullptr);
    if (m_size_) {
      delete temp;
    }
  }
  --m_size_;
}

template <typename T>
void my_space::List<T>::PushFront(const_reference value) {
  if (m_size_) {
    auto *temp = new Node<T>(value);
    temp->SetNext(node_start_);
    node_start_ = temp;
    ++m_size_;
  } else {
    PushBack(value);
  }
}

template <typename T>
void my_space::List<T>::PopFront() {
  auto *temp = node_start_;
  if (m_size_ > 1) {
    node_start_ = node_start_->GetNext();
    node_start_->SetPrev(nullptr);
    delete temp;
  } else {
    node_start_ = node_finish_ = node_end_;
    node_end_->SetNext(nullptr);
    node_end_->SetPrev(nullptr);
    if (m_size_) {
      delete temp;
    }
  }
  --m_size_;
}

template <typename T>
void my_space::List<T>::Swap(List &other) {
  List<T> temp(std::move(other));
  other = std::move(*this);
  *this = std::move(temp);
}

template <typename T>
void my_space::List<T>::Merge(List &other) {
  if (this != &other) {
    node_finish_->SetNext(other.node_start_);
    other.node_start_->SetPrev(node_finish_);
    node_finish_ = other.node_finish_;
    other.node_finish_->SetNext(node_end_);
    node_end_->SetPrev(other.node_finish_);
    m_size_ = m_size_ + other.m_size_;
    Sort();
    other.m_size_ = 0;
    other.node_start_ = other.node_finish_ = other.node_end_;
  }
}

template <typename T>
void my_space::List<T>::Splice(const_iterator pos, List &other) {
  iterator iter(const_cast<Node<T> *>(pos.GetPos()));
  if (this != &other) {
    if (iter.GetPos() == node_start_) {
      other.node_finish_->SetNext(node_start_);
      node_start_->SetPrev(other.node_finish_);
      node_start_ = other.node_start_;
    } else if (iter == End()) {
      node_finish_->SetNext(other.node_start_);
      other.node_start_->SetPrev(node_finish_);
      other.node_finish_->SetNext(node_end_);
      node_end_->SetPrev(other.node_finish_);
    } else {
      iterator prev = iter;
      --prev;
      prev.GetPos()->SetNext(other.node_start_);
      other.node_start_->SetPrev(prev.GetPos());
      iter.GetPos()->SetPrev(other.node_finish_);
      other.node_finish_->SetNext(iter.GetPos());
    }
    m_size_ = m_size_ + other.m_size_;
    other.m_size_ = 0;
    other.node_start_ = other.node_finish_ = other.node_end_;
  }
}

template <typename T>
void my_space::List<T>::Reverse() {
  auto iter_at_start = Begin();
  auto iter_from_the_end = End();
  --iter_from_the_end;
  for (size_t i = 0; i < m_size_ / 2;
       ++i, ++iter_at_start, --iter_from_the_end) {
    T temp = iter_at_start.GetPos()->GetInfo();
    iter_at_start.GetPos()->SetInfo(iter_from_the_end.GetPos()->GetInfo());
    iter_from_the_end.GetPos()->SetInfo(temp);
  }
}

template <typename T>
void my_space::List<T>::Unique() {
  for (auto current = Begin(); current != End(); ++current) {
    auto next = current;
    ++next;
    for (; current.GetPos()->GetInfo() == next.GetPos()->GetInfo() &&
           next != End();) {
      iterator temp = next;
      ++next;
      Erase(temp);
    }
  }
}

template <typename T>
void my_space::List<T>::Sort() {
  if (m_size_ > 1) {
    auto stop = End();
    --stop;
    for (auto first = Begin(); first != End(); ++first) {
      auto current = Begin();
      ++current;
      for (auto second = Begin(); second != stop; ++second, ++current) {
        if (second.GetPos()->GetInfo() > current.GetPos()->GetInfo()) {
          Node<T> temp(second.GetPos()->GetInfo());
          second.GetPos()->SetInfo(current.GetPos()->GetInfo());
          current.GetPos()->SetInfo(temp.GetInfo());
        }
      }
      --stop;
    }
  }
}

template <typename T>
template <typename... Args>
void my_space::List<T>::EmplaceBack(Args &&...args) {
  PushBack(T(args...));
}

template <typename T>
template <typename... Args>
void my_space::List<T>::EmplaceFront(Args &&...args) {
  PushFront(T(args...));
}

template <typename T>
template <typename... Args>
typename my_space::List<T>::iterator my_space::List<T>::Emplace(const_iterator pos,
                                                      Args &&...args) {
  iterator iter(const_cast<Node<T> *>(pos.GetPos()));
  return Insert(iter, T(args...));
}

#endif  // CONTAINERS_SRC_CONTAINER_LIST_H
