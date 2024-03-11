#ifndef CONTAINERS_SRC_BACKEND_NODE_LIST_H
#define CONTAINERS_SRC_BACKEND_NODE_LIST_H

namespace BackendListNode {
template <typename T>
class Node {
 public:
  Node();

  explicit Node(const T &value);

  Node(const Node &other) = delete;

  Node(Node &&other) = delete;

  ~Node() = default;

  T GetInfo() const;

  T &GetInfo();

  Node<T> *GetNext() const;

  Node<T> *GetNext();

  Node<T> *GetPrev() const;

  Node<T> *GetPrev();

  void SetInfo(const T &value);

  void SetNext(Node<T> *next);

  void SetPrev(Node<T> *prev);

 private:
  T info_;
  Node<T> *p_next_;
  Node<T> *p_prev_;
};

template <typename T>
Node<T>::Node() : p_next_(nullptr), p_prev_(nullptr) {}

template <typename T>
Node<T>::Node(const T &value)
    : info_(value), p_next_(nullptr), p_prev_(nullptr) {}

//// ГЕТЕРЫ
template <typename T>
T Node<T>::GetInfo() const {
  return info_;
}

template <typename T>
T &Node<T>::GetInfo() {
  return info_;
}

template <typename T>
Node<T> *Node<T>::GetNext() const {
  return p_next_;
}

template <typename T>
Node<T> *Node<T>::GetNext() {
  return p_next_;
}

template <typename T>
Node<T> *Node<T>::GetPrev() const {
  return p_prev_;
}

template <typename T>
Node<T> *Node<T>::GetPrev() {
  return p_prev_;
}

//// СЕТЕРЫ
template <typename T>
void Node<T>::SetInfo(const T &value) {
  info_ = value;
}

template <typename T>
void Node<T>::SetNext(Node<T> *next) {
  p_next_ = next;
  if (next) {
    next->p_prev_ = this;
  }
}

template <typename T>
void Node<T>::SetPrev(Node<T> *prev) {
  p_prev_ = prev;
  if (prev) {
    prev->p_next_ = this;
  }
}

}  // namespace BackendListNode
#endif  // CONTAINERS_SRC_BACKEND_NODE_LIST_H
