#ifndef ALGORITHM_TEMPLEATE_STACK_H
#define ALGORITHM_TEMPLEATE_STACK_H

#include <queue>
#include <stack>
#include <vector>

namespace algorithm_template {

// https://leetcode.cn/problems/implement-stack-using-queues/
class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    int size = q_.size();
    q_.push(x);
    for (int i = 0; i < size; i++) {
      int v = q_.front();
      q_.pop();
      q_.push(v);
    }
  }

  int pop() {
    int ret = q_.front();
    q_.pop();
    return ret;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }

 private:
  std::queue<int> q_;
};

// https://leetcode.cn/problems/min-stack/
class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    st_.push(val);
    if (minst_.empty() || val <= minst_.top()) {
      minst_.push(val);
    }
  }

  void pop() {
    int ret = st_.top();
    st_.pop();
    if (!minst_.empty() && ret == minst_.top()) {
      minst_.pop();
    }
  }

  int top() { return st_.top(); }

  int getMin() { return minst_.top(); }

 private:
  std::stack<int> st_;
  std::stack<int> minst_;
};

}  // namespace algorithm_template
#endif  // ALGORITHM_TEMPLEATE_STACK_H
