#ifndef ALGORITHM_TEMPLATE_HEAP_H
#define ALGORITHM_TEMPLATE_HEAP_H

#include <concepts>
#include <functional>
#include <optional>
#include <vector>
/*
i 的父节点 (i - 1) / 2
i 的左子节点 (2 * i) + 1
i 的右子节点 (2 * i) + 2
*/

namespace algorithm_template {

template <typename T, typename Compare = std::less<T>>
void HeapifyUp(std::vector<T>& arr, size_t idx, const Compare& cmp) {
  while (idx > 0) {
    size_t parent = (idx - 1) / 2;
    // 默认大根堆 传入less
    // 如果idx 小于 parent
    // 则调整已经完成
    if (cmp(arr[idx], arr[parent])) {
      break;
    }
    std::swap(arr[idx], arr[parent]);
    idx = parent;
  }
}
template <typename T, typename Compare = std::less<T>>
void HeapifyDown(std::vector<T>& arr, size_t idx, size_t size,
                 const Compare& cmp) {
  while (true) {
    size_t l = 2 * idx + 1;
    size_t r = 2 * idx + 2;
    size_t target = idx;

    if (l < size && cmp(arr[target], arr[l])) {
      target = l;
    }
    if (r < size && cmp(arr[target], arr[r])) {
      target = r;
    }
    if (target == idx) {
      break;
    }
    std::swap(arr[idx], arr[target]);
    idx = target;
  }
}

// 默认大根堆 传入less
template <typename T, typename Compare = std::less<T>>
class Heap {
 public:
  Heap() : cmp_(Compare()) {}
  explicit Heap(Compare cmp) : cmp_(cmp) {}

  // 获得原数组所有权
  explicit Heap(std::vector<T>&& arr) : cmp_(Compare()) {
    data_ = std::move(arr);
    // 从最后一个非叶子节点开始调整
    // o(n)
    for (int i = (data_.size() - 1) / 2; i >= 0; i--) {
      HeapifyDown(data_, i, data_.size(), cmp_);
    }
  }

  void Push(const T& value) {
    data_.push_back(value);
    HeapifyUp(data_, data_.size() - 1, cmp_);
  }

  void Pop() {
    if (data_.empty()) {
      return;
    }
    std::swap(data_.front(), data_.back());
    data_.pop_back();
    HeapifyDown(data_, 0, data_.size(), cmp_);
  }

  std::optional<T> Top() const {
    if (data_.empty()) {
      return std::nullopt;
    }
    return data_.front();
  }

  bool Empty() const { return data_.empty(); }
  size_t Size() const { return data_.size(); }

 private:
  std::vector<T> data_;
  Compare cmp_;
};

// https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
int MaxCover(const std::vector<std::vector<int>> lines);
int MaxCoverWithHeap(std::vector<std::vector<int>> lines);
// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/
int HalveArray(std::vector<int>& nums);
}  // namespace algorithm_template

#endif  // ALGORITHM_TEMPLATE_HEAP_H