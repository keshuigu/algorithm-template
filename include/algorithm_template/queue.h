#ifndef ALGORITHM_TEMPLATE_QUEUE_H
#define ALGORITHM_TEMPLATE_QUEUE_H

#include <stack>
#include <vector>
namespace algorithm_template {
// https://leetcode.cn/problems/design-circular-queue/
class MyCircularQueue {
 public:
  MyCircularQueue(int k) : buffer_(k + 1), size_(k + 1), left_(0), right_(0) {}

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    buffer_[right_] = value;
    right_ = (right_ + 1) % size_;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    left_ = (left_ + 1) % size_;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return buffer_[left_];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return buffer_[(right_ - 1 + size_) % size_];
  }

  bool isEmpty() { return left_ == right_; }

  bool isFull() { return (right_ + 1) % size_ == left_; }

 private:
  std::vector<int> buffer_;
  int size_;
  int left_;
  int right_;
};

// https://leetcode.cn/problems/design-circular-deque/
class MyCircularDeque {
 public:
  MyCircularDeque(int k) : buffer_(k + 1), size_(k + 1), left_(0), right_(0) {}

  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }
    left_ = (left_ - 1 + size_) % size_;
    buffer_[left_] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }
    buffer_[right_] = value;
    right_ = (right_ + 1) % size_;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }
    left_ = (left_ + 1) % size_;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    right_ = (right_ - 1 + size_) % size_;
    return true;
  }

  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return buffer_[left_];
  }

  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return buffer_[(right_ - 1 + size_) % size_];
  }

  bool isEmpty() { return left_ == right_; }

  bool isFull() { return (right_ + 1) % size_ == left_; }

 private:
  std::vector<int> buffer_;
  int size_;
  int left_;
  int right_;
};

// https://leetcode.cn/problems/implement-queue-using-stacks/
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { in_st_.push(x); }

  int pop() {
    if (out_st_.empty()) {
      InToOut();
    }
    int ret = out_st_.top();
    out_st_.pop();
    return ret;
  }

  int peek() {
    if (out_st_.empty()) {
      InToOut();
    }
    return out_st_.top();
  }

  bool empty() { return in_st_.empty() && out_st_.empty(); }

 private:
  void InToOut() {
    while (!in_st_.empty()) {
      out_st_.push(in_st_.top());
      in_st_.pop();
    }
  }
  std::stack<int> in_st_;
  std::stack<int> out_st_;
};
}  // namespace algorithm_template

#endif  // ALGORITHM_TEMPLATE_QUEUE_H