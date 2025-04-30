#include "algorithm_template/divide_conquer.h"

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
    if ((long long )arr[p1] <= 2LL * arr[p2]) {
      tmp += r -p2 + 1;
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
}  // namespace algorithm_template
