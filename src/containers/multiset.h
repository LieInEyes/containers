#ifndef CONTAINERS_SRC_CONTAINER_MULTISET_H
#define CONTAINERS_SRC_CONTAINER_MULTISET_H

#include "../backend/backend_multiset_Tree.h"

namespace my_space {
using namespace BackendMultiSet;
template <typename Value>
class MultiSet {
 public:
  using key_value = Value;
  using value_type = Value;
  using Tree = MultiTree<value_type>;
  using Node = BackendSet::Node<value_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename Tree::IteratorTree;
  using const_iterator = typename Tree::ConstIteratorTree;

  MultiSet() = default;
  explicit MultiSet(const std::initializer_list<value_type> &items);
  MultiSet(const MultiSet<value_type> &other);
  MultiSet(MultiSet<value_type> &&other) noexcept = default;
  ~MultiSet() = default;
  MultiSet<value_type> &operator=(MultiSet &&m) noexcept = default;

  iterator Begin();
  iterator End();

  bool Empty() noexcept;
  size_t Size();
  size_t Maxsize() const noexcept;

  void Clear() noexcept;
  std::pair<iterator, bool> Insert(const value_type &value);
  void Erase(iterator pos);
  void Swap(MultiSet<value_type> &other);
  void Merge(MultiSet<value_type> &other);
  bool Contains(const key_value &key) const;
  size_t Count(const key_value &key);
  iterator Find(const key_value &key);
  std::pair<iterator, iterator> Equal_range(const key_value &key);
  iterator Lower_bound(const key_value &key);
  iterator Upper_bound(const key_value &key);
  template <typename... Args>
  std::pair<iterator, bool> Emplace(Args &&...args);

 protected:
  Tree tree_;
};

template <typename Value>
MultiSet<Value>::MultiSet(const std::initializer_list<value_type> &items) {
  for (const value_type &item : items) {
    tree_.Insert(item);
  }
}

template <typename Value>
MultiSet<Value>::MultiSet(const MultiSet<Value> &other) : tree_(other.tree_) {}

template <typename Value>
typename MultiSet<Value>::iterator MultiSet<Value>::Begin() {
  return tree_.Begin();
}

template <typename Value>
typename MultiSet<Value>::iterator MultiSet<Value>::End() {
  return tree_.End();
}

template <typename Value>
bool MultiSet<Value>::Empty() noexcept {
  return tree_.Empty();
}

template <typename Value>
size_t MultiSet<Value>::Size() {
  return tree_.Size();
}

template <typename Value>
size_t MultiSet<Value>::Maxsize() const noexcept {
  return tree_.MaxSize();
}

template <typename Value>
void MultiSet<Value>::Clear() noexcept {
  tree_.Clear();
}

template <typename Value>
std::pair<typename MultiSet<Value>::iterator, bool> MultiSet<Value>::Insert(
    const value_type &value) {
  return tree_.Insert(value);
}

template <typename Value>
void MultiSet<Value>::Erase(iterator pos) {
  tree_.DeleteNode(tree_.At(*pos));
}

template <typename Value>
void MultiSet<Value>::Swap(MultiSet<Value> &other) {
  tree_.Swap(other.tree_);
}

template <typename Value>
void MultiSet<Value>::Merge(MultiSet<Value> &other) {
  if (!other.Empty()) {
    for (iterator iter = other.Begin(); iter != other.End(); ++iter) {
      Insert(*iter);
    }
    other.Clear();
  }
}

template <typename Value>
bool MultiSet<Value>::Contains(const Value &key) const {
  return tree_.Contains(key);
}

template <typename Value>
size_t MultiSet<Value>::Count(const key_value &key) {
  Node *node = tree_.At(key);
  if (node) {
    return node->GetCount();
  }
  return 0;
}

template <typename Value>
typename MultiSet<Value>::iterator MultiSet<Value>::Find(const key_value &key) {
  Node *node = tree_.At(key);
  if (node) {
    return MultiSet<Value>::iterator(node, &tree_);
  }
  return End();
}

template <typename Value>
std::pair<typename MultiSet<Value>::iterator,
          typename MultiSet<Value>::iterator>
MultiSet<Value>::Equal_range(const key_value &key) {
  return std::make_pair(Lower_bound(key), Upper_bound(key));
}

template <typename Value>
typename MultiSet<Value>::iterator MultiSet<Value>::Lower_bound(
    const key_value &key) {
  Node *node = tree_.At(key);
  return iterator(node, tree_, 1);
}

template <typename Value>
typename MultiSet<Value>::iterator MultiSet<Value>::Upper_bound(
    const key_value &key) {
  Node *node = tree_.At(key);
  return iterator(node, tree_, node->GetCount());
}

template <typename Value>
template <typename... Args>
std::pair<typename MultiSet<Value>::iterator, bool> MultiSet<Value>::Emplace(
    Args &&...args) {
  return tree_.Emplace(std::forward<Args>(args)...);
}
}  // namespace my_space

#endif  // CONTAINERS_SRC_CONTAINER_MULTISET_H
