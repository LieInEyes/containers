#ifndef CONTAINERS_SRC_CONTAINER_SET_H
#define CONTAINERS_SRC_CONTAINER_SET_H

#include "../backend/backend_set_Tree.h"

namespace my_space {
using namespace BackendSet;
template <typename Value>
class Set {
 public:
  using key_value = Value;
  using value_type = Value;
  using Tree = BackendSet::SetTree<value_type>;
  using Node = BackendSet::Node<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename Tree::IteratorTree;
  using const_iterator = typename Tree::ConstIteratorTree;

 public:
  Set() = default;
  explicit Set(const std::initializer_list<value_type> &items);
  Set(const Set<value_type> &other);
  Set(Set<value_type> &&other) noexcept;
  ~Set() = default;
  Set<value_type> &operator=(Set &&other) noexcept = default;

  iterator Begin();
  iterator End();

  bool Empty() noexcept;
  size_t Size();
  size_t Maxsize() const noexcept;

  void Clear() noexcept;
  std::pair<iterator, bool> Insert(const value_type &value);
  void Erase(iterator pos);
  void Swap(Set<value_type> &other);
  void Merge(Set<value_type> &other);

  iterator Find(const key_value &key);
  bool Contains(const key_value &key) const;

  template <typename... Args>
  std::pair<iterator, bool> Emplace(Args &&...args);

 protected:
  Tree tree_;
};

template <typename Value>
Set<Value>::Set(const std::initializer_list<value_type> &items) {
  for (const value_type &item : items) {
    tree_.Insert(item);
  }
}

template <typename Value>
Set<Value>::Set(const Set<Value> &other) {
  Clear();
  tree_ = other.tree_;
}

template <typename Value>
Set<Value>::Set(Set<value_type> &&other) noexcept {
  Clear();
  tree_ = std::move(other.tree_);
}

template <typename Value>
typename Set<Value>::iterator Set<Value>::Find(const Value &key) {
  Node *node = tree_.At(key);
  if (node) {
    return iterator(node, &tree_);
  }
  return End();
}

template <typename Value>
typename Set<Value>::iterator Set<Value>::Begin() {
  return tree_.Begin();
}

template <typename Value>
typename Set<Value>::iterator Set<Value>::End() {
  return tree_.End();
}

template <typename Value>
bool Set<Value>::Empty() noexcept {
  return tree_.Empty();
}

template <typename Value>
size_t Set<Value>::Size() {
  return tree_.Size();
}

template <typename Value>
size_t Set<Value>::Maxsize() const noexcept {
  return tree_.MaxSize();
}

template <typename Value>
void Set<Value>::Clear() noexcept {
  tree_.Clear();
}

template <typename Value>
std::pair<typename Set<Value>::iterator, bool> Set<Value>::Insert(
    const value_type &value) {
  return tree_.Insert(value);
}

template <typename Value>
void Set<Value>::Erase(iterator pos) {
  tree_.DeleteNode(tree_.At(*pos));
}

template <typename Value>
void Set<Value>::Swap(Set<Value> &other) {
  tree_.Swap(other.tree_);
}

template <typename Value>
void Set<Value>::Merge(Set<Value> &other) {
  if (!other.Empty()) {
    for (iterator iter = other.Begin(); iter; ++iter) {
      Insert(*iter);
    }
    other.Clear();
  }
}

template <typename Value>
bool Set<Value>::Contains(const Value &key) const {
  return tree_.Contains(key);
}

template <typename Value>
template <typename... Args>
std::pair<typename Set<Value>::iterator, bool> Set<Value>::Emplace(
    Args &&...args) {
  return tree_.Emplace(std::forward<Args>(args)...);
}
}  // namespace my_space

#endif  // CONTAINERS_SRC_CONTAINER_SET_H
