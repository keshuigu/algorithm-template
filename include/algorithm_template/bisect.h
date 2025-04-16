#ifndef ALGORITHM_TEMPLATE_BISECT_
#define ALGORITHM_TEMPLATE_BISECT_

#include <concepts>
#include <vector>

namespace algorithm_template {
// 返回有序arr中是否存在x
template <std::totally_ordered T>
bool Exist(const std::vector<T>& arr, T x) {
  if (arr.size() == 0) {
    return false;
  }
  int left = -1;
  int right = arr.size();
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == x) {
      return true;
    } else if (arr[mid] > x) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return false;
}
// 有序数组中>=x的最左位置
template <std::totally_ordered T>
int FindLeft(const std::vector<T>& arr, T x) {
  int left = -1;
  int right = arr.size();
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= x) {
      right = mid;
    } else {
      left = mid;
    }
  }
  // x > arr[arr.size()-1]时，返回arr.size()
  return right;
}
// 有序数组中<=x的最右位置
template <std::totally_ordered T>
int FindRight(const std::vector<T>& arr, T x) {
  int left = -1;
  int right = arr.size();
  while (left + 1 < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= x) {
      left = mid;
    } else {
      right = mid;
    }
  }
  // x < arr[0]时，返回-1
  return left;
}

// 寻找任意一个峰值
// https://leetcode.cn/problems/find-peak-element/description/
int FindPeak(const std::vector<int>& arr) {
  if (arr.size() <= 1) {
    return 0;
  }
  if (arr[0] > arr[1]) {
    return 0;
  }
  if (arr[arr.size() - 1] > arr[arr.size() - 2]) {
    return arr.size() - 1;
  }
  // 此时有arr.size >= 3 && arr[0] < arr[1] && arr[arr.size() - 2] >
  // arr[arr.size() - 1] 二分
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
      return mid;
    }
    else if (arr[mid - 1] > arr[mid]){
      right = mid;
    }else{
      left = mid;
    }
  }
  // never reach
  return -1;
}
}  // namespace algorithm_template

#endif