#ifndef CONTAINERS_SRC_BACKEND_BACKEND_SET_NODE_H
#define CONTAINERS_SRC_BACKEND_BACKEND_SET_NODE_H

#include <iostream>

namespace BackendSetNode {

const bool NODE_COLOR_BLACK = false;
const bool NODE_COLOR_RED = true;
const bool NODE_LEFT = true;
const bool NODE_RIGHT = false;

template <typename Value>
class Node {
  using type_value = Value;
  using size_type = size_t;

 public:
  Node();
  explicit Node(Value &value);
  Node(const Node<Value> &other);
  Node(Node<Value> &&other) noexcept;
  ~Node();

  Node<Value> *GetParent();
  Node<Value> *GetLeft();
  Node<Value> *GetRight();

  void SetParent(Node<Value> *node);
  void SetLeft(Node<Value> *node);
  void SetRight(Node<Value> *node);

  size_type IncrementCount();
  size_type DecrementCount();

  Value GetValue();
  Value *GetValuePtr();
  Value &GetValueRef();
  void SetValue(Value value);
  size_type GetCount();
  void SetCount(size_type new_count);

  bool IsRed();
  void ChangeColor();
  void SetColor(bool color);

  bool IsLeft();
  bool IsRight();
  bool HasLeft();
  bool HasRight();
  bool HasParent();

  size_t GetCountChildren();
  Node<Value> *GetHasChildren();
  bool CheckChildrenOnBlack();
  bool CheckColorLeftChildren();
  bool CheckColorRightChildren();

  Node<Value> &operator=(const Node &other) = default;
  Node<Value> &operator=(Node &&other) noexcept = default;

 private:
  type_value value_;
  bool is_red_ = true;
  Node<Value> *parent_{nullptr};
  Node<Value> *left_{nullptr};
  Node<Value> *right_{nullptr};
  size_type count_{};
};

template <typename Value>
Node<Value>::~Node() {
  if (parent_) {
    if (IsLeft()) {
      parent_->SetLeft(nullptr);
    } else {
      parent_->SetRight(nullptr);
    }
  }
  left_ = nullptr;
  right_ = nullptr;
  parent_ = nullptr;
}

template <typename Value>
Node<Value>::Node(Node<Value>::type_value &value) : value_(value), count_(1) {}

template <typename Value>
Node<Value>::Node() : value_(nullptr), count_(1) {}

template <typename Value>
Node<Value>::Node(const Node<Value> &other) {
  *this = other;
}

template <typename Value>
Node<Value>::Node(Node<Value> &&other) noexcept {
  *this = std::move(other);
}

template <typename Value>
Node<Value> *Node<Value>::GetParent() {
  return parent_;
}

template <typename Value>
Node<Value> *Node<Value>::GetLeft() {
  return left_;
}

template <typename Value>
Node<Value> *Node<Value>::GetRight() {
  return right_;
}

template <typename Value>
void Node<Value>::SetParent(Node<Value> *node) {
  parent_ = node;
}

template <typename Value>
void Node<Value>::SetLeft(Node<Value> *node) {
  left_ = node;
  if (node) {
    node->SetParent(this);
  }
}

template <typename Value>
void Node<Value>::SetRight(Node<Value> *node) {
  right_ = node;
  if (node) {
    node->SetParent(this);
  }
}

template <typename Value>
Value Node<Value>::GetValue() {
  return value_;
}

template <typename Value>
Value *Node<Value>::GetValuePtr() {
  return &value_;
}

template <typename Value>
Value &Node<Value>::GetValueRef() {
  return value_;
}

template <typename Value>
void Node<Value>::SetValue(Value value) {
  value_ = value;
}

template <typename Value>
typename Node<Value>::size_type Node<Value>::GetCount() {
  return count_;
}

template <typename Value>
void Node<Value>::SetCount(size_type new_count) {
  count_ = new_count;
}

template <typename Value>
typename Node<Value>::size_type Node<Value>::IncrementCount() {
  return ++count_;
}

template <typename Value>
typename Node<Value>::size_type Node<Value>::DecrementCount() {
  return --count_;
}

template <typename Value>
bool Node<Value>::IsRed() {
  return is_red_;
}

template <typename Value>
void Node<Value>::ChangeColor() {
  is_red_ = !is_red_;
}

template <typename Value>
void Node<Value>::SetColor(bool color) {
  is_red_ = color;
}

template <typename Value>
bool Node<Value>::IsLeft() {
  return this == parent_->left_;
}

template <typename Value>
bool Node<Value>::IsRight() {
  return this == parent_->right_;
}

template <typename Value>
bool Node<Value>::HasLeft() {
  return left_ != nullptr;
}

template <typename Value>
bool Node<Value>::HasRight() {
  return right_ != nullptr;
}

template <typename Value>
bool Node<Value>::HasParent() {
  return parent_ != nullptr;
}

template <typename Value>
size_t Node<Value>::GetCountChildren() {
  return HasRight() + HasLeft();
}

template <typename Value>
Node<Value> *Node<Value>::GetHasChildren() {
  if (HasLeft()) {
    return left_;
  }
  return right_;
}

template <typename Value>
bool Node<Value>::CheckChildrenOnBlack() {
  bool left_node, right_node;
  left_node = !CheckColorLeftChildren();
  right_node = !CheckColorRightChildren();
  return left_node && right_node;
}

template <typename Value>
bool Node<Value>::CheckColorLeftChildren() {
  if (!HasLeft() || !left_->is_red_) {
    return NODE_COLOR_BLACK;
  }
  return NODE_COLOR_RED;
}

template <typename Value>
bool Node<Value>::CheckColorRightChildren() {
  if (!HasRight() || !right_->is_red_) {
    return NODE_COLOR_BLACK;
  }
  return NODE_COLOR_RED;
}
}  // namespace BackendSetNode

#endif  // CONTAINERS_SRC_BACKEND_BACKEND_SET_NODE_H
