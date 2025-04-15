#ifndef ALGORITHM_TEMPLATE_SORT_
#define ALGORITHM_TEMPLATE_SORT_

#include <concepts>
#include <utility>
#include <vector>
namespace algorithm_template {

template <std::totally_ordered T>
void SelectSort(std::vector<T>& arr) {
  if (arr.size() < 2) {
    return;
  }
  for (size_t i = 0; i < arr.size() - 1; i++) {
    size_t idx = i;
    for (size_t j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[idx]) {
        idx = j;
      }
    }
    std::swap(arr[i], arr[idx]);
  }
}

template <std::totally_ordered T>
void BubbleSort(std::vector<T>& arr) {
  if (arr.size() < 2) {
    return;
  }
  for (size_t i = arr.size() - 1; i > 0; i--) {
    for (size_t j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

template <std::totally_ordered T>
void InsertSort(std::vector<T>& arr) {
  if (arr.size() < 2) {
    return;
  }
  for (size_t i = 1; i < arr.size(); i++) {
    for (size_t j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      std::swap(arr[j], arr[j - 1]);
    }
  }
}

}  // namespace algorithm_template


#endif