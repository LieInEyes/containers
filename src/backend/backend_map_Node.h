#ifndef CONTAINERS_SRC_BACKEND_BACKEND_MAP_NODE_H
#define CONTAINERS_SRC_BACKEND_BACKEND_MAP_NODE_H

#include <iostream>

namespace BackendMap {

const bool NODE_COLOR_BLACK = false;
const bool NODE_COLOR_RED = true;
const bool NODE_LEFT = true;
const bool NODE_RIGHT = false;

template <typename Key, typename Value>
class Node {
  using type_value = std::pair<Key, Value>;

 public:
  Node();
  Node(Key &key, Value &value);
  explicit Node(type_value &value);
  Node(const Node<Key, Value> &other);
  Node(Node<Key, Value> &&other) noexcept;
  ~Node();

  Node<Key, Value> *GetParent();
  Node<Key, Value> *GetLeft();
  Node<Key, Value> *GetRight();

  void SetParent(Node<Key, Value> *node);
  void SetLeft(Node<Key, Value> *node);
  void SetRight(Node<Key, Value> *node);

  Value GetValue();
  Value &GetValueRef();
  void SetValue(Value value);
  Key GetKey();
  type_value GetKeyValue();
  type_value *GetKeyValuePtr();
  void SetKeyValue(type_value value);

  bool IsRed();
  void ChangeColor();
  void SetColor(bool color);

  bool IsLeft();
  bool IsRight();
  bool HasLeft();
  bool HasRight();
  bool HasParent();

  size_t GetCountChildren();
  Node<Key, Value> *GetHasChildren();
  bool CheckChildrenOnBlack();
  bool CheckColorLeftChildren();
  bool CheckColorRightChildren();

  Node<Key, Value> &operator=(const Node &other) = default;
  Node<Key, Value> &operator=(Node &&other) noexcept = default;

 private:
  type_value value_;
  bool is_red_ = true;
  Node<Key, Value> *parent_{nullptr};
  Node<Key, Value> *left_{nullptr};
  Node<Key, Value> *right_{nullptr};
};

template <typename Key, typename Value>
Node<Key, Value>::~Node() {
  if (parent_) {
    if (IsLeft()) {
      parent_->SetLeft(nullptr);
    } else {
      parent_->SetRight(nullptr);
    }
  }
  parent_ = nullptr;
  left_ = nullptr;
  right_ = nullptr;
}

template <typename Key, typename Value>
Node<Key, Value>::Node(Node::type_value &value) : value_(value) {}

template <typename Key, typename Value>
Node<Key, Value>::Node() : value_(nullptr) {}

template <typename Key, typename Value>
Node<Key, Value>::Node(Key &key, Value &value)
    : value_(std::make_pair(key, value)) {}

template <typename Key, typename Value>
Node<Key, Value>::Node(const Node<Key, Value> &other) {
  *this = other;
}

template <typename Key, typename Value>
Node<Key, Value>::Node(Node<Key, Value> &&other) noexcept {
  *this = std::move(other);
}

template <typename Key, typename Value>
Node<Key, Value> *Node<Key, Value>::GetParent() {
  return parent_;
}

template <typename Key, typename Value>
Node<Key, Value> *Node<Key, Value>::GetLeft() {
  return left_;
}

template <typename Key, typename Value>
Node<Key, Value> *Node<Key, Value>::GetRight() {
  return right_;
}

template <typename Key, typename Value>
void Node<Key, Value>::SetParent(Node<Key, Value> *node) {
  parent_ = node;
}

template <typename Key, typename Value>
void Node<Key, Value>::SetLeft(Node<Key, Value> *node) {
  left_ = node;
  if (node) {
    node->SetParent(this);
  }
}

template <typename Key, typename Value>
void Node<Key, Value>::SetRight(Node<Key, Value> *node) {
  right_ = node;
  if (node) {
    node->SetParent(this);
  }
}

template <typename Key, typename Value>
Value Node<Key, Value>::GetValue() {
  return value_.second;
}

template <typename Key, typename Value>
void Node<Key, Value>::SetValue(Value value) {
  value_.second = value;
}

template <typename Key, typename Value>
Value &Node<Key, Value>::GetValueRef() {
  return value_.second;
}

template <typename Key, typename Value>
Key Node<Key, Value>::GetKey() {
  return value_.first;
}

template <typename Key, typename Value>
std::pair<Key, Value> Node<Key, Value>::GetKeyValue() {
  return value_;
}

template <typename Key, typename Value>
std::pair<Key, Value> *Node<Key, Value>::GetKeyValuePtr() {
  return &value_;
}

template <typename Key, typename Value>
void Node<Key, Value>::SetKeyValue(type_value value) {
  value_ = value;
}

template <typename Key, typename Value>
bool Node<Key, Value>::IsRed() {
  return is_red_;
}

template <typename Key, typename Value>
void Node<Key, Value>::ChangeColor() {
  is_red_ = !is_red_;
}

template <typename Key, typename Value>
void Node<Key, Value>::SetColor(bool color) {
  is_red_ = color;
}

template <typename Key, typename Value>
bool Node<Key, Value>::IsLeft() {
  return this == parent_->left_;
}

template <typename Key, typename Value>
bool Node<Key, Value>::IsRight() {
  return this == parent_->right_;
}

template <typename Key, typename Value>
bool Node<Key, Value>::HasLeft() {
  return left_ != nullptr;
}

template <typename Key, typename Value>
bool Node<Key, Value>::HasRight() {
  return right_ != nullptr;
}

template <typename Key, typename Value>
bool Node<Key, Value>::HasParent() {
  return parent_ != nullptr;
}

template <typename Key, typename Value>
size_t Node<Key, Value>::GetCountChildren() {
  return HasRight() + HasLeft();
}

template <typename Key, typename Value>
Node<Key, Value> *Node<Key, Value>::GetHasChildren() {
  if (HasLeft()) {
    return left_;
  }
  return right_;
}

template <typename Key, typename Value>
bool Node<Key, Value>::CheckChildrenOnBlack() {
  bool left_node, right_node;
  left_node = !CheckColorLeftChildren();
  right_node = !CheckColorRightChildren();
  return left_node && right_node;
}

template <typename Key, typename Value>
bool Node<Key, Value>::CheckColorLeftChildren() {
  if (!HasLeft() || !left_->is_red_) {
    return NODE_COLOR_BLACK;
  }
  return NODE_COLOR_RED;
}

template <typename Key, typename Value>
bool Node<Key, Value>::CheckColorRightChildren() {
  if (!HasRight() || !right_->is_red_) {
    return NODE_COLOR_BLACK;
  }
  return NODE_COLOR_RED;
}
}  // namespace BackendMap

#endif  // CONTAINERS_SRC_BACKEND_BACKEND_MAP_NODE_H
