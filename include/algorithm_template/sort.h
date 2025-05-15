#ifndef ALGORITHM_TEMPLATE_SORT_H
#define ALGORITHM_TEMPLATE_SORT_H

#include <concepts>
#include <random>
#include <utility>
#include <vector>

#include "algorithm_template/heap.h"
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

template <std::totally_ordered T>
int Partition0(std::vector<T>& arr, int l, int r, int x) {
  int idx = l, xi = 0;
  for (int i = l; i <= r; i++) {
    if (arr[i] <= x) {
      std::swap(arr[i], arr[idx]);
      if (arr[idx] == x) {
        xi = idx;
      }
      idx++;
    }
  }
  //  将任意一个等于x的下标交换到 <=x的最后一个位置
  std::swap(arr[xi], arr[idx - 1]);
  return idx - 1;
}

template <std::totally_ordered T>
void RandomQuickSort0(std::vector<T>& arr, int l, int r, std::mt19937 gen) {
  if (l >= r) {
    return;
  }
  std::uniform_int_distribution<> dis(l, r);
  int x = arr[dis(gen)];
  int m = Partition0(arr, l, r, x);
  RandomQuickSort0(arr, l, m - 1, gen);
  RandomQuickSort0(arr, m + 1, r, gen);
}

template <std::totally_ordered T>
std::pair<int, int> Partition1(std::vector<T>& arr, int l, int r, int x) {
  int li = l, ri = r;
  int i = l;
  while (i <= ri) {
    if (arr[i] < x) {
      std::swap(arr[i], arr[li]);
      li++;
      i++;
    } else if (arr[i] > x) {
      std::swap(arr[i], arr[ri]);
      ri--;
    } else {
      i++;
    }
  }
  return {li, ri};
}

template <std::totally_ordered T>
void RandomQuickSort1(std::vector<T>& arr, int l, int r, std::mt19937 gen) {
  if (l >= r) {
    return;
  }
  std::uniform_int_distribution<> dis(l, r);
  int x = arr[dis(gen)];
  auto [li, ri] = Partition1(arr, l, r, x);
  RandomQuickSort1(arr, l, li - 1, gen);
  RandomQuickSort1(arr, ri + 1, r, gen);
}

template <std::totally_ordered T>
void RandomQuickSort(std::vector<T>& arr) {
  std::random_device rd;
  std::mt19937 gen(rd());
  RandomQuickSort0(arr, 0, arr.size() - 1, gen);
}

template <std::totally_ordered T>
void RandomQuickSortImprove(std::vector<T>& arr) {
  std::random_device rd;
  std::mt19937 gen(rd());
  RandomQuickSort1(arr, 0, arr.size() - 1, gen);
}

template <std::totally_ordered T>
void HeapSort(std::vector<T>& arr) {
  std::less<T> cmp;
  for (int i = (arr.size() - 1) / 2; i >= 0; i--) {
    HeapifyDown(arr, i,arr.size(), cmp);
  }
  for (int i = arr.size() - 1; i > 0; i--) {
    std::swap(arr[i],arr[0]);
    HeapifyDown(arr,0,i,cmp);
  }
}

}  // namespace algorithm_template

#endif  // ALGORITHM_TEMPLATE_SORT_H