#ifndef CONTAINERS_SRC_BACKEND_BACKEND_SET_TREE_H
#define CONTAINERS_SRC_BACKEND_BACKEND_SET_TREE_H

#include <iostream>
#include <limits>

#include "backend_set_Node.h"

namespace BackendSet {

const bool TREE_NODE_SET_LEFT = true;
const bool TREE_NODE_SET_RIGHT = false;

using namespace BackendSetNode;

template <typename Value>
class SetTree {
 public:
  class IteratorTree;
  class ConstIteratorTree;
  using key_type = Value;
  using value_type = Value;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = IteratorTree;
  using const_iterator = ConstIteratorTree;

 public:
  class IteratorTree {
   public:
    IteratorTree();
    IteratorTree(Node<Value> *current, SetTree<Value> *tree);
    IteratorTree(const IteratorTree &other) = default;
    IteratorTree(IteratorTree &&other) noexcept = default;
    ~IteratorTree() = default;

    bool operator==(const IteratorTree &other) const;
    bool operator!=(const IteratorTree &other) const;
    IteratorTree operator++();
    IteratorTree operator--();
    value_type operator*();
    explicit operator bool() const;
    virtual value_type *operator->() const;

   protected:
    Node<Value> *current_{nullptr};
    Node<Value> *first_{nullptr};
    Node<Value> *last_{nullptr};

    void Increment();
    void Decrement();
    virtual Node<Value> *GetCurr() const;
  };

  class ConstIteratorTree : public IteratorTree {
   protected:
    const Node<Value> *GetCurr();

   public:
    ConstIteratorTree();
    ConstIteratorTree(Node<Value> *current, SetTree<Value> *tree);
    const value_type *operator->() const override;
  };

  SetTree();
  explicit SetTree(value_type value);
  explicit SetTree(std::initializer_list<value_type> const &items);
  SetTree(const SetTree<Value> &other);
  SetTree(SetTree<Value> &&other) noexcept;
  ~SetTree();

  SetTree &operator=(const SetTree<value_type> &other);
  SetTree &operator=(SetTree<value_type> &&other) noexcept;

  IteratorTree Begin();
  IteratorTree End();

  bool Empty();
  std::pair<IteratorTree, bool> Insert(value_type value);
  template <typename... Args>
  std::pair<IteratorTree, bool> Emplace(Args &&...args);
  bool Contains(const value_type &value) const;
  Node<Value> *At(const value_type &value);
  size_t Size() const;
  size_t MaxSize() const;
  void Clear();
  void Swap(SetTree<Value> &other);
  void DeleteNode(Node<Value> *node);

 protected:
  Node<Value> *CreateNode(value_type value);
  void CopyTree(Node<Value> *curr);
  Node<Value> *GetFirstNode() const;
  Node<Value> *GetLastNode() const;
  static Node<Value> *MoveToLastRight(Node<Value> *node);
  static Node<Value> *MoveToLastLeft(Node<Value> *node);
  static Node<Value> *MoveIncrementToRight(Node<Value> *node);
  static Node<Value> *MoveIncrementToUp(Node<Value> *node);
  static Node<Value> *MoveDecrementToLeft(Node<Value> *node);
  static Node<Value> *MoveDecrementToUp(Node<Value> *node);
  Node<Value> *FixBalanceInsertLeft(Node<Value> *node);
  Node<Value> *FixBalanceInsertRight(Node<Value> *node);
  void FixBalanceInsert(Node<Value> *node);
  Node<Value> *GetUncle(Node<Value> *node) const;
  Node<Value> *GetBrother(Node<Value> *node) const;
  void RotateLeft(Node<Value> *node);
  void RotateRight(Node<Value> *node);
  std::pair<Node<Value> *, bool> FindSpaceByNode(value_type value);
  std::pair<Node<Value> *, bool> InsertPair(value_type value);
  std::pair<Node<Value> *, bool> InsertNode(Node<Value> *node);
  void DeleteTree(Node<Value> *node);
  void FixBalanceDelete(Node<Value> *node);
  void FixBalanceDeleteRed(Node<Value> *node);
  void FixBalanceDeletePrepareSubtree(Node<Value> *brother,
                                      Node<Value> *grandson);
  void FixBalanceDeleteLastIteration(Node<Value> *brother,
                                     Node<Value> *grandson);
  void ChangeValueNode(Node<Value> *one, Node<Value> *two);

  Node<Value> *root_;
  size_t size_ = 0;
};

/*
 * method SetTree
 * */
template <typename Value>
Node<Value> *SetTree<Value>::CreateNode(value_type value) {
  return new Node<Value>(value);
}

template <typename Value>
SetTree<Value>::SetTree() {
  root_ = nullptr;
  size_ = 0;
}

template <typename Value>
SetTree<Value>::SetTree(value_type value)
    : root_(CreateNode(value)), size_(1) {}

template <typename Value>
SetTree<Value>::SetTree(const std::initializer_list<value_type> &items)
    : SetTree() {
  for (const_reference item : items) {
    Insert(item);
  }
}

template <typename Value>
SetTree<Value>::SetTree(const SetTree<Value> &other) {
  CopyTree(other.root_);
}

template <typename Value>
SetTree<Value>::SetTree(SetTree<Value> &&other) noexcept {
  root_ = other.root_;
  other.root_ = nullptr;
}

template <typename Value>
SetTree<Value>::~SetTree() {
  DeleteTree(root_);
}

template <typename Value>
SetTree<Value> &SetTree<Value>::operator=(const SetTree<value_type> &other) {
  if (root_) {
    DeleteTree(root_);
  }
  CopyTree(other.root_);
  return *this;
}

template <typename Value>
SetTree<Value> &SetTree<Value>::operator=(
    SetTree<value_type> &&other) noexcept {
  if (root_) {
    DeleteTree(root_);
  }
  root_ = other.root_;
  size_ = other.size_;
  other.root_ = nullptr;
  other.size_ = 0;
  return *this;
}

template <typename Value>
void SetTree<Value>::CopyTree(Node<Value> *curr) {
  if (!curr) {
    return;
  }
  InsertPair(curr->GetValue());
  CopyTree(curr->GetLeft());
  CopyTree(curr->GetRight());
}

template <typename Value>
bool SetTree<Value>::Empty() {
  return root_ == nullptr;
}

template <typename Value>
Node<Value> *SetTree<Value>::GetFirstNode() const {
  if (root_) {
    return MoveToLastLeft(root_);
  }
  return nullptr;
}

template <typename Value>
Node<Value> *SetTree<Value>::GetLastNode() const {
  if (root_) {
    return MoveToLastRight(root_);
  }
  return nullptr;
}

template <typename Value>
Node<Value> *SetTree<Value>::MoveToLastRight(Node<Value> *node) {
  for (; node->HasRight();) {
    node = node->GetRight();
  }
  return node;
}

template <typename Value>
Node<Value> *SetTree<Value>::MoveToLastLeft(Node<Value> *node) {
  for (; node->HasLeft();) {
    node = node->GetLeft();
  }
  return node;
}

template <typename Value>
Node<Value> *SetTree<Value>::MoveIncrementToRight(Node<Value> *node) {
  node = node->GetRight();
  node = MoveToLastLeft(node);
  return node;
}

template <typename Value>
Node<Value> *SetTree<Value>::MoveIncrementToUp(Node<Value> *node) {
  for (; node->IsRight();) {
    node = node->GetParent();
  }
  return node->GetParent();
}

template <typename Value>
Node<Value> *SetTree<Value>::MoveDecrementToLeft(Node<Value> *node) {
  node = node->GetLeft();
  return MoveToLastRight(node);
}

template <typename Value>
Node<Value> *SetTree<Value>::MoveDecrementToUp(Node<Value> *node) {
  for (; node->IsLeft();) {
    node = node->GetParent();
  }
  return node->GetParent();
}

template <typename Value>
void SetTree<Value>::RotateLeft(Node<Value> *node) {
  Node<Value> *temp_node = node->GetRight();
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

template <typename Value>
void SetTree<Value>::RotateRight(Node<Value> *node) {
  Node<Value> *temp_node = node->GetLeft();
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

template <typename Value>
Node<Value> *SetTree<Value>::FixBalanceInsertLeft(Node<Value> *node) {
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

template <typename Value>
Node<Value> *SetTree<Value>::FixBalanceInsertRight(Node<Value> *node) {
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

template <typename Value>
void SetTree<Value>::FixBalanceInsert(Node<Value> *node) {
  if (node->HasParent() && node->GetParent()->IsRed()) {
    for (; node->GetParent()->IsRed();) {
      Node<Value> *uncle = GetUncle(node);
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

template <typename Value>
Node<Value> *SetTree<Value>::GetUncle(Node<Value> *node) const {
  node = node->GetParent();
  if (node->IsRight()) {
    node = node->GetParent()->GetLeft();
  } else {
    node = node->GetParent()->GetRight();
  }
  return node;
}

template <typename Value>
Node<Value> *SetTree<Value>::GetBrother(Node<Value> *node) const {
  if (node->IsLeft()) {
    return node->GetParent()->GetRight();
  }
  return node->GetParent()->GetLeft();
}

template <typename Value>
typename SetTree<Value>::IteratorTree SetTree<Value>::Begin() {
  Node<Value> *first = GetFirstNode();
  return IteratorTree(first, this);
}

template <typename Value>
typename SetTree<Value>::IteratorTree SetTree<Value>::End() {
  return IteratorTree(nullptr, this);
}

template <typename Value>
std::pair<Node<Value> *, bool> SetTree<Value>::FindSpaceByNode(
    SetTree<Value>::value_type value) {
  Node<Value> *current = root_;
  for (; current && value != current->GetValue();) {
    if (value < current->GetValue()) {
      if (current->HasLeft()) {
        current = current->GetLeft();
        continue;
      }
      return std::make_pair(current, TREE_NODE_SET_LEFT);
    }
    if (value > current->GetValue()) {
      if (current->HasRight()) {
        current = current->GetRight();
        continue;
      }
      return std::make_pair(current, TREE_NODE_SET_RIGHT);
    }
  }
  return std::make_pair(nullptr, TREE_NODE_SET_LEFT);
}

template <typename Value>
std::pair<Node<Value> *, bool> SetTree<Value>::InsertPair(value_type value) {
  Node<Value> *current = root_;
  if (current) {
    std::pair<Node<Value> *, bool> point = FindSpaceByNode(value);
    if (point.first) {
      Node<Value> *node = CreateNode(value);
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

template <typename Value>
std::pair<Node<Value> *, bool> SetTree<Value>::InsertNode(Node<Value> *node) {
  Node<Value> *current = root_;
  std::pair<Node<Value> *, bool> point = FindSpaceByNode(node->GetValue());
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

template <typename Value>
void SetTree<Value>::DeleteTree(Node<Value> *node) {
  if (node) {
    DeleteTree(node->GetLeft());
    DeleteTree(node->GetRight());
    delete node;
  }
}

template <typename Value>
void SetTree<Value>::DeleteNode(Node<Value> *node) {
  if (!node) {
    return;
  }
  Node<Value> *temp_node;
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

template <typename Value>
void SetTree<Value>::FixBalanceDelete(Node<Value> *node) {
  for (Node<Value> *brother = GetBrother(node);; brother = GetBrother(node)) {
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
      Node<Value> *grandson;
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

template <typename Value>
void SetTree<Value>::FixBalanceDeleteRed(Node<Value> *node) {
  node->ChangeColor();
  Node<Value> *parent = node->GetParent();
  parent->ChangeColor();
  if (node->IsLeft()) {
    RotateRight(parent);
  } else {
    RotateLeft(parent);
  }
}

template <typename Value>
void SetTree<Value>::FixBalanceDeletePrepareSubtree(Node<Value> *brother,
                                                    Node<Value> *grandson) {
  brother->ChangeColor();
  grandson->ChangeColor();
  if (grandson->IsLeft()) {
    RotateRight(brother);
  } else {
    RotateLeft(brother);
  }
}

template <typename Value>
void SetTree<Value>::FixBalanceDeleteLastIteration(Node<Value> *brother,
                                                   Node<Value> *grandson) {
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

template <typename Value>
void SetTree<Value>::ChangeValueNode(Node<Value> *one, Node<Value> *two) {
  value_type temp_value = one->GetValue();
  one->SetValue(two->GetValue());
  two->SetValue(temp_value);
}

template <typename Value>
std::pair<typename SetTree<Value>::IteratorTree, bool> SetTree<Value>::Insert(
    value_type value) {
  std::pair<Node<Value> *, bool> result = InsertPair(value);
  if (result.second) {
    FixBalanceInsert(result.first);
    return std::make_pair(IteratorTree(result.first, this), result.second);
  }
  return std::make_pair(IteratorTree(GetLastNode(), this), result.second);
}

template <typename Value>
template <typename... Args>
std::pair<typename SetTree<Value>::IteratorTree, bool> SetTree<Value>::Emplace(
    Args &&...args) {
  auto *insert_node = new Node<Value>(args...);
  std::pair<Node<Value> *, bool> result = InsertNode(insert_node);
  if (!result.second) {
    Node<Value> *old_node = At(insert_node->GetValue());
    delete insert_node;
    return std::make_pair(IteratorTree(old_node, this), false);
  }
  return std::make_pair(IteratorTree(insert_node, this), true);
}

template <typename Value>
bool SetTree<Value>::Contains(const Value &value) const {
  Node<Value> *current = root_;
  for (; current && current->GetValue() != value;) {
    if (value < current->GetValue()) {
      current = current->GetLeft();
    } else {
      current = current->GetRight();
    }
  }
  return current != nullptr;
}

template <typename Value>
Node<Value> *SetTree<Value>::At(const Value &value) {
  Node<Value> *current = root_;
  for (; current && current->GetValue() != value;) {
    if (value < current->GetValue()) {
      current = current->GetLeft();
    } else {
      current = current->GetRight();
    }
  }
  return current;
}

template <typename Value>
size_t SetTree<Value>::Size() const {
  return size_;
}

template <typename Value>
size_t SetTree<Value>::MaxSize() const {
  return std::numeric_limits<size_t>::max() / sizeof(Node<Value>) / 2;
}

template <typename Value>
void SetTree<Value>::Clear() {
  if (root_) {
    DeleteTree(root_);
    size_ = 0;
    root_ = nullptr;
  }
}

template <typename Value>
void SetTree<Value>::Swap(SetTree<Value> &other) {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
}

/*
 * method IteratorTree
 * */

template <typename Value>
void SetTree<Value>::IteratorTree::Increment() {
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

template <typename Value>
void SetTree<Value>::IteratorTree::Decrement() {
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

template <typename Value>
SetTree<Value>::IteratorTree::IteratorTree()
    : first_(nullptr), current_(nullptr), last_(nullptr) {}

template <typename Value>
SetTree<Value>::IteratorTree::IteratorTree(Node<Value> *current,
                                           SetTree<Value> *tree)
    : current_(current),
      first_(tree->GetFirstNode()),
      last_(tree->GetLastNode()) {}

template <typename Value>
Node<Value> *SetTree<Value>::IteratorTree::GetCurr() const {
  return current_;
}

template <typename Value>
typename SetTree<Value>::IteratorTree
SetTree<Value>::IteratorTree::operator++() {
  Increment();
  return *this;
}

template <typename Value>
typename SetTree<Value>::IteratorTree
SetTree<Value>::IteratorTree::operator--() {
  Decrement();
  return *this;
}

template <typename Value>
typename SetTree<Value>::value_type SetTree<Value>::IteratorTree::operator*() {
  return current_->GetValue();
}

template <typename Value>
bool SetTree<Value>::IteratorTree::operator!=(const IteratorTree &other) const {
  if (!other.current_ && !current_) {
    return false;
  }
  if (other.current_ && current_) {
    return other.current_->GetValue() != current_->GetValue();
  }
  return true;
}

template <typename Value>
bool SetTree<Value>::IteratorTree::operator==(const IteratorTree &other) const {
  if (!other.current_ && !current_) {
    return true;
  }
  if (other.current_ && current_) {
    return other.current_->GetValue() == current_->GetValue();
  }
  return false;
}

template <typename Value>
SetTree<Value>::IteratorTree::operator bool() const {
  return current_ != nullptr;
}

template <typename Value>
typename SetTree<Value>::value_type *SetTree<Value>::IteratorTree::operator->()
    const {
  return current_->GetValuePtr();
}

/*
 * methods ConstIteratorTree
 * */

template <typename Value>
SetTree<Value>::ConstIteratorTree::ConstIteratorTree() : IteratorTree() {}

template <typename Value>
SetTree<Value>::ConstIteratorTree::ConstIteratorTree(Node<Value> *current,
                                                     SetTree<Value> *tree)
    : IteratorTree(current, tree) {}

template <typename Value>
const Node<Value> *SetTree<Value>::ConstIteratorTree::GetCurr() {
  return this->current_;
}

template <typename Value>
const typename SetTree<Value>::value_type *
SetTree<Value>::ConstIteratorTree::operator->() const {
  return this->current_->GetValue();
}
}  // namespace BackendSet

#endif  // CONTAINERS_SRC_BACKEND_BACKEND_SET_TREE_H
