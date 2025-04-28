#ifndef ALGORITHM_TEMPLATE_SORT_H
#define ALGORITHM_TEMPLATE_SORT_H

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

// merge function
template <std::totally_ordered T>
void Merge(std::vector<T>& arr, int l, int m, int r) {
  std::vector<T> tmp;
  tmp.reserve(r - l + 1);
  int p1 = l, p2 = m + 1;
  while (p1 <= m && p2 <= r) {
    if (arr[p1] <= arr[p2]) {
      tmp.push_back(arr[p1]);
      p1++;
    } else {
      tmp.push_back(arr[p2]);
      p2++;
    }
  }
  while (p1 <= m) {
    tmp.push_back(arr[p1]);
    p1++;
  }
  while (p2 <= m) {
    tmp.push_back(arr[p2]);
    p2++;
  }
  for (int i = 0; i < tmp.size(); i++) {
    arr[l + i] = tmp[i];
  }
}

// T(N) = 2 * t(N/2) + O(N)
template <std::totally_ordered T>
void MergeSort0(std::vector<T>& arr, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  MergeSort0(arr, l, m);
  MergeSort0(arr, m + 1, r);
  Merge(arr, l, m, r);
}

template <std::totally_ordered T>
void MergeSort(std::vector<T>& arr) {
  MergeSort0(arr, 0, arr.size() - 1);
}

template <std::totally_ordered T>
void MergeSortNoRecursion(std::vector<T>& arr) {
  int n = arr.size();
  for (int step = 1; step < n; step = step * 2) {
    int l = 0;
    while (l < n) {
      int m = l + step - 1;
      // 无右侧
      if (m + 1 >= n) {
        break;
      }
      int r = std::min(l + step * 2 - 1, n - 1);
      Merge(arr, l, m, r);
      l = r + 1;
    }
  }
}

}  // namespace algorithm_template

#endif  // ALGORITHM_TEMPLATE_SORT_H