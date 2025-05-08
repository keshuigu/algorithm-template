#include "algorithm_template/divide_conquer.h"

#include <random>

#include "algorithm_template/sort.h"  // merge
namespace algorithm_template {

namespace {
long long SmallSum0(std::vector<int>& arr, int l, int r) {
  if (l >= r) {
    return 0;
  }
  int m = l + (r - l) / 2;
  long long res = 0;
  res += SmallSum0(arr, l, m);
  res += SmallSum0(arr, m + 1, r);
  int p1 = l;
  int p2 = m + 1;
  int k = 0;
  std::vector<int> temp(r - l + 1);
  while (p1 <= m && p2 <= r) {
    if (arr[p1] <= arr[p2]) {
      res += (long long)(arr[p1]) * (long long)(r - p2 + 1);
      temp[k++] = arr[p1++];
    } else {
      temp[k++] = arr[p2++];
    }
  }
  // 处理剩余部分
  while (p1 <= m) {
    temp[k++] = arr[p1++];
  }
  while (p2 <= r) {
    temp[k++] = arr[p2++];
  }

  // 将临时数组拷贝回原数组
  for (int i = 0; i < temp.size(); i++) {
    arr[l + i] = temp[i];
  }
  // Merge(arr, l, m, r);// 整合到上面的while中
  return res;
}

}  // namespace

long long SmallSum(std::vector<int>& arr) {
  return SmallSum0(arr, 0, arr.size() - 1);
}

namespace {
int ReversePairs0(std::vector<int>& arr, int l, int r) {
  if (l >= r) {
    return 0;
  }
  long long res = 0;
  int m = l + (r - l) / 2;
  res += ReversePairs0(arr, l, m);
  res += ReversePairs0(arr, m + 1, r);
  int p1 = l;
  int p2 = m + 1;
  int k = 0;
  long long tmp = 0;
  while (p1 <= m && p2 <= r) {
    if ((long long)arr[p1] <= 2LL * arr[p2]) {
      tmp += r - p2 + 1;
      p1++;
    } else {
      p2++;
    }
  }
  Merge(arr, l, m, r);
  return (int)(res + (long long)(m - l + 1) * (r - m) - tmp);
}
}  // namespace

int ReversePairs(std::vector<int>& arr) {
  return ReversePairs0(arr, 0, arr.size() - 1);
}

namespace {

std::pair<int, int> PartitionFindKthLargest(std::vector<int>& arr, int l, int r,
                                            int x) {
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

int FindKthLargest0(std::vector<int>& arr, int l, int r, int k,
                    std::mt19937 gen) {
  std::uniform_int_distribution<> dis(l, r);
  int x = arr[dis(gen)];
  auto [li, ri] = PartitionFindKthLargest(arr, l, r, x);
  if (k < li) {
    return FindKthLargest0(arr, l, li - 1, k, gen);
  } else if (k > ri) {
    return FindKthLargest0(arr, ri + 1, r, k, gen);
  } else {
    return x;
  }
}

}  // namespace

int FindKthLargest(const std::vector<int>& nums, int k) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<int> tmp(nums.begin(), nums.end());
  // 递归
  // return FindKthLargest0(tmp, 0, tmp.size() - 1, k, gen);
  // 迭代
  for (int l = 0, r = tmp.size() - 1; l <= r;) {
    std::uniform_int_distribution<> dis(l, r);
    auto [li, ri] = PartitionFindKthLargest(tmp, l, r, tmp[dis(gen)]);
    if (k > ri) {
      l = ri + 1;
    } else if (k < li) {
      r = li - 1;
    } else {
      return tmp[k];
    }
  }
  return -1;
}
}  // namespace algorithm_template
