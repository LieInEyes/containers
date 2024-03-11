#ifndef CONTAINERS_SRC_TESTS_TEST_CLASS_H
#define CONTAINERS_SRC_TESTS_TEST_CLASS_H

#include <iostream>

class TestObj {
 public:
  TestObj() : name_("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"), num_entries_(7776777) {}
  TestObj(std::string const &name, int num) : name_(name), num_entries_(num) {}

  double GetNum() const { return num_entries_; }
  std::string GetName() const { return name_; }

  bool operator>(TestObj &other) {
    if (name_ > other.name_ && num_entries_ > other.num_entries_) {
      return true;
    } else {
      return false;
    }
  }

  bool operator<(TestObj &other) {
    if (name_ < other.name_ && num_entries_ < other.num_entries_) {
      return true;
    } else {
      return false;
    }
  }

  bool operator==(TestObj &other) {
    if (name_ == other.name_ && num_entries_ == other.num_entries_) {
      return true;
    } else {
      return false;
    }
  }

 private:
  std::string name_;
  double num_entries_;
};

#endif  // CONTAINERS_SRC_TESTS_TEST_CLASS_H
