#ifndef CONTAINERS_SRC_BACKEND_BACKEND_MAP_TREE_H
#define CONTAINERS_SRC_BACKEND_BACKEND_MAP_TREE_H

#include <iostream>
#include <limits>

#include "backend_map_Node.h"

namespace BackendMap {

const bool TREE_NODE_SET_LEFT = true;
const bool TREE_NODE_SET_RIGHT = false;

template <typename Key, typename Value>
class Tree {
  using type_value = std::pair<Key, Value>;

 public:
  class IteratorTree;

  Tree();
  explicit Tree(type_value value);
  explicit Tree(std::initializer_list<type_value> const &items);
  Tree(const Tree<Key, Value> &other);
  Tree(Tree<Key, Value> &&other) noexcept;
  ~Tree();

  IteratorTree Begin();
  IteratorTree End();

  std::pair<IteratorTree, bool> Insert(type_value value);
  std::pair<IteratorTree, bool> Assign(Node<Key, Value> *node,
                                       const Value &value);
  template <typename... Args>
  std::pair<IteratorTree, bool> Emplace(Args &&...args);

  bool Contains(const Key &key) const;
  Node<Key, Value> *At(const Key &key);
  bool Empty();
  size_t Size() const;
  size_t MaxSize() const;

  void Clear();
  void Swap(Tree<Key, Value> &other);
  void DeleteNode(Node<Key, Value> *node);

  class IteratorTree {
   public:
    IteratorTree();
    IteratorTree(Node<Key, Value> *current, Tree<Key, Value> *tree);
    IteratorTree(const IteratorTree &other) = default;
    IteratorTree(IteratorTree &&other) noexcept = default;
    ~IteratorTree() = default;

    virtual Node<Key, Value> *GetCurr() const;
    bool operator==(const IteratorTree &other) const;
    bool operator!=(const IteratorTree &other) const;
    IteratorTree operator++();
    IteratorTree operator--();
    explicit operator bool() const;
    virtual std::pair<Key, Value> *operator->() const;
    IteratorTree &operator=(const IteratorTree &other) = default;
    IteratorTree &operator=(IteratorTree &&other) noexcept = default;

   protected:
    Node<Key, Value> *current_{nullptr};
    Node<Key, Value> *first_{nullptr};
    Node<Key, Value> *last_{nullptr};

    void Increment();
    void Decrement();
  };

  class ConstIteratorTree : public IteratorTree {
   public:
    const Node<Key, Value> *GetCurr();
    ConstIteratorTree();
    ConstIteratorTree(Node<Key, Value> *current, Tree<Key, Value> *tree);
    ~ConstIteratorTree() = default;
    ConstIteratorTree &operator=(const ConstIteratorTree &other) = default;
    ConstIteratorTree &operator=(ConstIteratorTree &&other) noexcept = default;
    const type_value *operator->();
  };

 private:
  Node<Key, Value> *root_;
  size_t size_ = 0;

  Node<Key, Value> *CreateNode(type_value value);
  void CopyTree(Node<Key, Value> *curr);
  Node<Key, Value> *GetFirstNode() const;
  Node<Key, Value> *GetLastNode() const;
  static Node<Key, Value> *MoveToLastRight(Node<Key, Value> *node);
  static Node<Key, Value> *MoveToLastLeft(Node<Key, Value> *node);
  static Node<Key, Value> *MoveIncrementToRight(Node<Key, Value> *node);
  static Node<Key, Value> *MoveIncrementToUp(Node<Key, Value> *node);
  static Node<Key, Value> *MoveDecrementToLeft(Node<Key, Value> *node);
  static Node<Key, Value> *MoveDecrementToUp(Node<Key, Value> *node);
  Node<Key, Value> *FixBalanceInsertLeft(Node<Key, Value> *node);
  Node<Key, Value> *FixBalanceInsertRight(Node<Key, Value> *node);
  void FixBalanceInsert(Node<Key, Value> *node);
  Node<Key, Value> *GetUncle(Node<Key, Value> *node) const;
  Node<Key, Value> *GetBrother(Node<Key, Value> *node) const;
  void RotateLeft(Node<Key, Value> *node);
  void RotateRight(Node<Key, Value> *node);
  std::pair<Node<Key, Value> *, bool> FindSpaceByNode(Key value);
  std::pair<Node<Key, Value> *, bool> InsertPair(type_value value);
  std::pair<Node<Key, Value> *, bool> InsertNode(Node<Key, Value> *node);
  void DeleteTree(Node<Key, Value> *node);
  void FixBalanceDelete(Node<Key, Value> *node);
  void FixBalanceDeleteRed(Node<Key, Value> *node);
  void FixBalanceDeletePrepareSubtree(Node<Key, Value> *brother,
                                      Node<Key, Value> *grandson);
  void FixBalanceDeleteLastIteration(Node<Key, Value> *brother,
                                     Node<Key, Value> *grandson);
  void ChangeValueNode(Node<Key, Value> *one, Node<Key, Value> *two);
};

/*
 * method SetTree
 * */
template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::CreateNode(type_value value) {
  return new Node<Key, Value>(value);
}

template <typename Key, typename Value>
Tree<Key, Value>::Tree() {
  root_ = nullptr;
  size_ = 0;
}

template <typename Key, typename Value>
Tree<Key, Value>::Tree(type_value value) : root_(CreateNode(value)), size_(1) {}

template <typename Key, typename Value>
Tree<Key, Value>::Tree(const std::initializer_list<type_value> &items)
    : Tree() {
  for (const type_value &item : items) {
    Insert(item);
  }
}

template <typename Key, typename Value>
Tree<Key, Value>::Tree(const Tree<Key, Value> &other) : Tree() {
  CopyTree(other.root_);
}

template <typename Key, typename Value>
Tree<Key, Value>::Tree(Tree<Key, Value> &&other) noexcept : Tree() {
  root_ = other.root_;
  size_ = other.size_;
  other.root_ = nullptr;
}

template <typename Key, typename Value>
Tree<Key, Value>::~Tree() {
  DeleteTree(root_);
}

template <typename Key, typename Value>
void Tree<Key, Value>::CopyTree(Node<Key, Value> *curr) {
  if (!curr) {
    return;
  }
  InsertPair(std::make_pair(curr->GetKey(), curr->GetValue()));
  CopyTree(curr->GetLeft());
  CopyTree(curr->GetRight());
}

template <typename Key, typename Value>
bool Tree<Key, Value>::Empty() {
  return root_ == nullptr;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::GetFirstNode() const {
  if (root_) {
    return MoveToLastLeft(root_);
  }
  return nullptr;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::GetLastNode() const {
  if (root_) {
    return MoveToLastRight(root_);
  }
  return nullptr;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::MoveToLastRight(Node<Key, Value> *node) {
  for (; node->HasRight();) {
    node = node->GetRight();
  }
  return node;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::MoveToLastLeft(Node<Key, Value> *node) {
  for (; node->HasLeft();) {
    node = node->GetLeft();
  }
  return node;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::MoveIncrementToRight(
    Node<Key, Value> *node) {
  node = node->GetRight();
  node = MoveToLastLeft(node);
  return node;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::MoveIncrementToUp(Node<Key, Value> *node) {
  for (; node->IsRight();) {
    node = node->GetParent();
  }
  return node->GetParent();
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::MoveDecrementToLeft(
    Node<Key, Value> *node) {
  node = node->GetLeft();
  return MoveToLastRight(node);
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::MoveDecrementToUp(Node<Key, Value> *node) {
  for (; node->IsLeft();) {
    node = node->GetParent();
  }
  return node->GetParent();
}

template <typename Key, typename Value>
void Tree<Key, Value>::RotateLeft(Node<Key, Value> *node) {
  Node<Key, Value> *temp_node = node->GetRight();
  node->SetRight(temp_node->GetLeft());
  if (!node->HasParent()) {
    root_ = temp_node;
    temp_node->SetParent(nullptr);
  } else if (node->IsLeft()) {
    node->GetParent()->SetLeft(temp_node);
  } else {
    node->GetParent()->SetRight(temp_node);
  }
  temp_node->SetLeft(node);
}

template <typename Key, typename Value>
void Tree<Key, Value>::RotateRight(Node<Key, Value> *node) {
  Node<Key, Value> *temp_node = node->GetLeft();
  node->SetLeft(temp_node->GetRight());
  if (!node->HasParent()) {
    root_ = temp_node;
    temp_node->SetParent(nullptr);
  } else if (node->IsRight()) {
    node->GetParent()->SetRight(temp_node);
  } else {
    node->GetParent()->SetLeft(temp_node);
  }
  temp_node->SetRight(node);
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::FixBalanceInsertLeft(
    Node<Key, Value> *node) {
  if (node->IsRight()) {
    node = node->GetParent();
    RotateLeft(node);
  }
  node->GetParent()->ChangeColor();
  node = node->GetParent()->GetParent();
  node->ChangeColor();
  RotateRight(node);
  return node;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::FixBalanceInsertRight(
    Node<Key, Value> *node) {
  if (node->IsLeft()) {
    node = node->GetParent();
    RotateRight(node);
  }
  node->GetParent()->ChangeColor();
  node = node->GetParent()->GetParent();
  if (node) {
    node->ChangeColor();
    RotateLeft(node);
  }
  return node;
}

template <typename Key, typename Value>
void Tree<Key, Value>::FixBalanceInsert(Node<Key, Value> *node) {
  if (node->HasParent() && node->GetParent()->IsRed()) {
    for (; node->GetParent()->IsRed();) {
      Node<Key, Value> *uncle = GetUncle(node);
      if (uncle && uncle->IsRed()) {
        uncle->ChangeColor();
        node->GetParent()->ChangeColor();
        node = node->GetParent()->GetParent();
        node->ChangeColor();
      } else {
        if (node->GetParent()->IsLeft()) {
          node = FixBalanceInsertLeft(node);
        } else {
          node = FixBalanceInsertRight(node);
        }
      }
      if (node == root_) {
        break;
      }
    }
  }
  if (node == root_) {
    node->SetColor(NODE_COLOR_BLACK);
  }
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::GetUncle(Node<Key, Value> *node) const {
  node = node->GetParent();
  if (node->IsRight()) {
    node = node->GetParent()->GetLeft();
  } else {
    node = node->GetParent()->GetRight();
  }
  return node;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::GetBrother(Node<Key, Value> *node) const {
  if (node->IsLeft()) {
    return node->GetParent()->GetRight();
  }
  return node->GetParent()->GetLeft();
}

template <typename Key, typename Value>
typename Tree<Key, Value>::IteratorTree Tree<Key, Value>::Begin() {
  Node<Key, Value> *first = GetFirstNode();
  return IteratorTree(first, this);
}

template <typename Key, typename Value>
typename Tree<Key, Value>::IteratorTree Tree<Key, Value>::End() {
  return IteratorTree(nullptr, this);
}

template <typename Key, typename Value>
std::pair<Node<Key, Value> *, bool> Tree<Key, Value>::FindSpaceByNode(
    Key value) {
  Node<Key, Value> *current = root_;
  for (; current && value != current->GetKey();) {
    if (value < current->GetKey()) {
      if (current->HasLeft()) {
        current = current->GetLeft();
        continue;
      }
      return std::make_pair(current, TREE_NODE_SET_LEFT);
    }
    if (value > current->GetKey()) {
      if (current->HasRight()) {
        current = current->GetRight();
        continue;
      }
      return std::make_pair(current, TREE_NODE_SET_RIGHT);
    }
  }
  return std::make_pair(nullptr, TREE_NODE_SET_LEFT);
}

template <typename Key, typename Value>
std::pair<Node<Key, Value> *, bool> Tree<Key, Value>::InsertPair(
    type_value value) {
  Node<Key, Value> *current = root_;
  if (current) {
    std::pair<Node<Key, Value> *, bool> point = FindSpaceByNode(value.first);
    if (point.first) {
      Node<Key, Value> *node = CreateNode(value);
      if (point.second == TREE_NODE_SET_LEFT) {
        point.first->SetLeft(node);
      } else {
        point.first->SetRight(node);
      }
      ++size_;
      return std::make_pair(node, true);
    }
  } else {
    root_ = CreateNode(value);
    ++size_;
    return std::make_pair(root_, true);
  }
  return std::make_pair(current, false);
}

template <typename Key, typename Value>
std::pair<Node<Key, Value> *, bool> Tree<Key, Value>::InsertNode(
    Node<Key, Value> *node) {
  Node<Key, Value> *current = root_;
  std::pair<Node<Key, Value> *, bool> point = FindSpaceByNode(node->GetKey());
  if (current) {
    if (point.first) {
      if (point.second == TREE_NODE_SET_LEFT) {
        point.first->SetLeft(node);
      } else {
        point.first->SetRight(node);
      }
      ++size_;
      return std::make_pair(node, true);
    }
  } else {
    root_ = node;
    ++size_;
    return std::make_pair(root_, true);
  }
  return std::make_pair(point.first, false);
}

template <typename Key, typename Value>
void Tree<Key, Value>::DeleteTree(Node<Key, Value> *node) {
  if (node) {
    DeleteTree(node->GetLeft());
    DeleteTree(node->GetRight());
    node->SetParent(nullptr);
    delete node;
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::DeleteNode(Node<Key, Value> *node) {
  if (!node) {
    return;
  }
  Node<Key, Value> *temp_node;
  for (auto count_children = node->GetCountChildren(); count_children;
       count_children = node->GetCountChildren()) {
    if (count_children == 2) {
      temp_node = MoveToLastLeft(node->GetRight());
      ChangeValueNode(node, temp_node);
      node = temp_node;
    } else if (count_children == 1) {
      temp_node = node->GetHasChildren();
      ChangeValueNode(node, temp_node);
      node = temp_node;
    }
  }
  if (!node->IsRed()) {
    FixBalanceDelete(node);
  }
  delete node;
  --size_;
}

template <typename Key, typename Value>
void Tree<Key, Value>::FixBalanceDelete(Node<Key, Value> *node) {
  for (Node<Key, Value> *brother = GetBrother(node);;
       brother = GetBrother(node)) {
    if (brother->IsRed()) {
      FixBalanceDeleteRed(brother);
      continue;
    } else {
      if (brother->CheckChildrenOnBlack()) {
        brother->ChangeColor();
        brother = brother->GetParent();
        bool color_parent = brother->IsRed();
        brother->SetColor(NODE_COLOR_BLACK);
        if (color_parent) {
          break;
        }
        node = brother;
        continue;
      }
      bool first_red, second_black;
      Node<Key, Value> *grandson;
      if (brother->IsLeft()) {
        first_red = brother->CheckColorRightChildren();
        second_black = !brother->CheckColorLeftChildren();
        grandson = brother->GetRight();
      } else {
        first_red = brother->CheckColorLeftChildren();
        second_black = !brother->CheckColorRightChildren();
        grandson = brother->GetLeft();
      }
      if (first_red && second_black) {
        FixBalanceDeletePrepareSubtree(brother, grandson);
        continue;
      }
      FixBalanceDeleteLastIteration(brother, grandson);
      break;
    }
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::FixBalanceDeleteRed(Node<Key, Value> *node) {
  node->ChangeColor();
  Node<Key, Value> *parent = node->GetParent();
  parent->ChangeColor();
  if (node->IsLeft()) {
    RotateRight(parent);
  } else {
    RotateLeft(parent);
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::FixBalanceDeletePrepareSubtree(
    Node<Key, Value> *brother, Node<Key, Value> *grandson) {
  brother->ChangeColor();
  grandson->ChangeColor();
  if (grandson->IsLeft()) {
    RotateRight(brother);
  } else {
    RotateLeft(brother);
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::FixBalanceDeleteLastIteration(
    Node<Key, Value> *brother, Node<Key, Value> *grandson) {
  brother->SetColor(brother->GetParent()->IsRed());
  brother->GetParent()->SetColor(NODE_COLOR_BLACK);
  if (brother->GetLeft() == grandson) {
    brother->GetRight()->SetColor(NODE_COLOR_BLACK);
    RotateLeft(brother->GetParent());
  } else {
    brother->GetLeft()->SetColor(NODE_COLOR_BLACK);
    RotateRight(brother->GetParent());
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::ChangeValueNode(Node<Key, Value> *one,
                                       Node<Key, Value> *two) {
  std::pair<Key, Value> temp_value = one->GetKeyValue();
  one->SetKeyValue(two->GetKeyValue());
  two->SetKeyValue(temp_value);
}

template <typename Key, typename Value>
std::pair<typename Tree<Key, Value>::IteratorTree, bool>
Tree<Key, Value>::Insert(type_value value) {
  std::pair<Node<Key, Value> *, bool> result = InsertPair(value);
  if (result.second) {
    FixBalanceInsert(result.first);
    return std::make_pair(IteratorTree(result.first, this), result.second);
  }
  return std::make_pair(IteratorTree(GetLastNode(), this), result.second);
}

template <typename Key, typename Value>
template <typename... Args>
std::pair<typename Tree<Key, Value>::IteratorTree, bool>
Tree<Key, Value>::Emplace(Args &&...args) {
  auto *insert_node = new Node<Key, Value>(args...);
  std::pair<Node<Key, Value> *, bool> result = InsertNode(insert_node);
  if (!result.second) {
    Node<Key, Value> *old_node = At(insert_node->GetKey());
    delete insert_node;
    return std::make_pair(IteratorTree(old_node, this), false);
  }
  return std::make_pair(IteratorTree(insert_node, this), true);
}

template <typename Key, typename Value>
std::pair<typename Tree<Key, Value>::IteratorTree, bool>
Tree<Key, Value>::Assign(Node<Key, Value> *node, const Value &value) {
  node->SetValue(value);
  return std::make_pair(IteratorTree(node, this), true);
}

template <typename Key, typename Value>
bool Tree<Key, Value>::Contains(const Key &key) const {
  Node<Key, Value> *current = root_;
  for (; current && current->GetKey() != key;) {
    if (key < current->GetKey()) {
      current = current->GetLeft();
    } else {
      current = current->GetRight();
    }
  }
  return current != nullptr;
}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::At(const Key &key) {
  Node<Key, Value> *current = root_;
  for (; current && current->GetKey() != key;) {
    if (key < current->GetKey()) {
      current = current->GetLeft();
    } else {
      current = current->GetRight();
    }
  }
  return current;
}

template <typename Key, typename Value>
size_t Tree<Key, Value>::Size() const {
  return size_;
}

template <typename Key, typename Value>
size_t Tree<Key, Value>::MaxSize() const {
  return std::numeric_limits<size_t>::max() / sizeof(Node<Key, Value>) / 2;
}

template <typename Key, typename Value>
void Tree<Key, Value>::Clear() {
  if (root_) {
    DeleteTree(root_);
    size_ = 0;
    root_ = nullptr;
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::Swap(Tree<Key, Value> &other) {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
}

/*
 * method IteratorTree
 * */

template <typename Key, typename Value>
void Tree<Key, Value>::IteratorTree::Increment() {
  if (current_ == last_) {
    current_ = nullptr;
    return;
  }
  if (current_->HasRight()) {
    current_ = MoveIncrementToRight(current_);
  } else {
    current_ = MoveIncrementToUp(current_);
  }
}

template <typename Key, typename Value>
void Tree<Key, Value>::IteratorTree::Decrement() {
  if (current_ == nullptr) {
    current_ = last_;
    return;
  }
  if (current_->HasLeft()) {
    current_ = MoveDecrementToLeft(current_);
  } else {
    current_ = MoveDecrementToUp(current_);
  }
}

template <typename Key, typename Value>
Tree<Key, Value>::IteratorTree::IteratorTree()
    : first_(nullptr), current_(nullptr), last_(nullptr) {}

template <typename Key, typename Value>
Tree<Key, Value>::IteratorTree::IteratorTree(Node<Key, Value> *current,
                                             Tree<Key, Value> *tree)
    : current_(current),
      first_(tree->GetFirstNode()),
      last_(tree->GetLastNode()) {}

template <typename Key, typename Value>
Node<Key, Value> *Tree<Key, Value>::IteratorTree::GetCurr() const {
  return current_;
}

template <typename Key, typename Value>
typename Tree<Key, Value>::IteratorTree
Tree<Key, Value>::IteratorTree::operator++() {
  Increment();
  return *this;
}

template <typename Key, typename Value>
typename Tree<Key, Value>::IteratorTree
Tree<Key, Value>::IteratorTree::operator--() {
  Decrement();
  return *this;
}

template <typename Key, typename Value>
bool Tree<Key, Value>::IteratorTree::operator!=(
    const IteratorTree &other) const {
  if (!other && !current_) {
    return false;
  }
  if (other && current_) {
    return other.current_->GetKey() != current_->GetKey();
  }
  return true;
}

template <typename Key, typename Value>
bool Tree<Key, Value>::IteratorTree::operator==(
    const IteratorTree &other) const {
  return other.current_->GetKey() == current_->GetKey();
}

template <typename Key, typename Value>
Tree<Key, Value>::IteratorTree::operator bool() const {
  return current_ != nullptr;
}

template <typename Key, typename Value>
std::pair<Key, Value> *Tree<Key, Value>::IteratorTree::operator->() const {
  return current_->GetKeyValuePtr();
}

/*
 * methods ConstIteratorTree
 * */

template <typename Key, typename Value>
Tree<Key, Value>::ConstIteratorTree::ConstIteratorTree() : IteratorTree() {}

template <typename Key, typename Value>
Tree<Key, Value>::ConstIteratorTree::ConstIteratorTree(
    Node<Key, Value> *current, Tree<Key, Value> *tree)
    : IteratorTree(current, tree) {}

template <typename Key, typename Value>
const Node<Key, Value> *Tree<Key, Value>::ConstIteratorTree::GetCurr() {
  return this->current_;
}

template <typename Key, typename Value>
const typename Tree<Key, Value>::type_value *
Tree<Key, Value>::ConstIteratorTree::operator->() {
  return this->current_->GetKeyValuePtr();
}
}  // namespace BackendMap

#endif  // CONTAINERS_SRC_BACKEND_BACKEND_MAP_TREE_H
