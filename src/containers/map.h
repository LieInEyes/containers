#ifndef CONTAINERS_SRC_CONTAINER_MAP_H
#define CONTAINERS_SRC_CONTAINER_MAP_H

#include "../backend/backend_map_Tree.h"

namespace my_space {
using namespace BackendMap;
template <typename Key, typename Value>
class Map {
 public:
  using key_value = Key;
  using mapped_type = Value;
  using value_type = std::pair<Key, Value>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename Tree<Key, Value>::IteratorTree;
  using const_iterator = typename Tree<Key, Value>::ConstIteratorTree;

 public:
  Map() = default;
  explicit Map(const std::initializer_list<value_type> &items);
  Map(const Map<key_value, mapped_type> &other);
  Map(Map<key_value, mapped_type> &&other) noexcept = default;
  ~Map() = default;
  Map<key_value, mapped_type> &operator=(Map &&m) noexcept = default;

  mapped_type &At(const key_value &key);
  mapped_type &operator[](const key_value &key);

  iterator Begin();
  iterator End();

  bool Empty() noexcept;
  size_t Size();
  size_t Maxsize() const noexcept;

  void Clear() noexcept;
  std::pair<iterator, bool> Insert(const value_type &value);
  std::pair<iterator, bool> Insert(const key_value &key,
                                   const mapped_type &obj);
  std::pair<iterator, bool> InsertOrAssign(const key_value &key,
                                           const mapped_type &obj);
  void Erase(iterator pos);
  void Swap(Map<key_value, mapped_type> &other);
  void Merge(Map<key_value, mapped_type> &other);
  bool Contains(const key_value &key) const;

  template <typename... Args>
  std::pair<typename Tree<Key, Value>::IteratorTree, bool> Emplace(
      Args &&...args);

 private:
  Tree<key_value, mapped_type> tree_;
};

template <typename Key, typename Value>
Map<Key, Value>::Map(const std::initializer_list<value_type> &items) {
  for (const value_type &item : items) {
    tree_.Insert(item);
  }
}

template <typename Key, typename Value>
Map<Key, Value>::Map(const Map<Key, Value> &other) : tree_(other.tree_) {}

template <typename Key, typename Value>
Value &Map<Key, Value>::At(const Key &key) {
  BackendMap::Node<Key, Value> *node = tree_.At(key);
  if (node == nullptr) {
    throw std::out_of_range("Index out of range");
  }
  return node->GetValueRef();
}

template <typename Key, typename Value>
Value &Map<Key, Value>::operator[](const Key &key) {
  return At(key);
}

template <typename Key, typename Value>
typename Map<Key, Value>::iterator Map<Key, Value>::Begin() {
  return tree_.Begin();
}

template <typename Key, typename Value>
typename Map<Key, Value>::iterator Map<Key, Value>::End() {
  return tree_.End();
}

template <typename Key, typename Value>
bool Map<Key, Value>::Empty() noexcept {
  return tree_.Empty();
}

template <typename Key, typename Value>
size_t Map<Key, Value>::Size() {
  return tree_.Size();
}

template <typename Key, typename Value>
size_t Map<Key, Value>::Maxsize() const noexcept {
  return tree_.MaxSize();
}

template <typename Key, typename Value>
void Map<Key, Value>::Clear() noexcept {
  tree_.Clear();
}

template <typename Key, typename Value>
std::pair<typename Map<Key, Value>::iterator, bool> Map<Key, Value>::Insert(
    const value_type &value) {
  return tree_.Insert(value);
}

template <typename Key, typename Value>
std::pair<typename Map<Key, Value>::iterator, bool> Map<Key, Value>::Insert(
    const Key &key, const Value &obj) {
  return tree_.Insert(std::make_pair(key, obj));
}

template <typename Key, typename Value>
std::pair<typename Map<Key, Value>::iterator, bool>
Map<Key, Value>::InsertOrAssign(const Key &key, const Value &obj) {
  BackendMap::Node<Key, Value> *node = tree_.At(key);
  if (node) {
    return tree_.Assign(node, obj);
  }
  return tree_.Insert(std::make_pair(key, obj));
}

template <typename Key, typename Value>
void Map<Key, Value>::Erase(iterator pos) {
  tree_.DeleteNode(tree_.At(pos->first));
}

template <typename Key, typename Value>
void Map<Key, Value>::Swap(Map<Key, Value> &other) {
  tree_.Swap(other.tree_);
}

template <typename Key, typename Value>
void Map<Key, Value>::Merge(Map<Key, Value> &other) {
  if (!other.Empty()) {
    for (iterator iter = other.Begin(); iter != other.End(); ++iter) {
      if (!Contains(iter->first)) {
        Insert(iter->first, iter->second);
        other.Erase(iter);
      }
    }
  }
}

template <typename Key, typename Value>
bool Map<Key, Value>::Contains(const Key &key) const {
  return tree_.Contains(key);
}

template <typename Key, typename Value>
template <typename... Args>
std::pair<typename Tree<Key, Value>::IteratorTree, bool>
Map<Key, Value>::Emplace(Args &&...args) {
  return tree_.Emplace(std::forward<Args>(args)...);
}
}  // namespace my_space

#endif  // CONTAINERS_SRC_CONTAINER_MAP_H
