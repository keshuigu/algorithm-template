#include "algorithm_template/sort.h"

namespace algorithm_template {

void RadixSort(std::vector<int>& arr) {
  std::vector<int> bucks[10];
  for (int i = 0; i < 10; i++) {
    int base = 1;
    for (int k = 0; k < i; k++) {
      base *= 10;
    }
    for (int j = 0; j < arr.size(); j++) {
      int x = arr[j];
      int cur = (arr[j] / base) % 10;
      bucks[cur].push_back(x);
    }
    int off = 0;
    for (int r = 0; r < 10; r++) {
      for (int m = 0; m < bucks[r].size(); m++) {
        arr[off++] = bucks[r][m];
      }
      bucks[r].clear();
    }
  }
}

void RadixSortLessRoom(std::vector<int>& arr) {
  int cnt[10];
  int pre[10];
  std::vector<int> t(arr.size());
  for (int i = 0; i < 10; i++) {
    int base = 1;
    for (int k = 0; k < i; k++) {
      base *= 10;
    }
    // clear
    for (int j = 0; j < 10; j++) {
      cnt[j] = 0;
    }
    for (int j = 0; j < arr.size(); j++) {
      int x = arr[j];
      int cur = (arr[j] / base) % 10;
      cnt[cur]++;
    }
    // calc pre
    pre[0] = cnt[0];
    for (int j = 1; j < 10; j++) {
      pre[j] = pre[j - 1] + cnt[j];
    }
    // sort
    // reverse read
    for (int j = arr.size() - 1; j >= 0; j--) {
      int x = arr[j];
      int cur = (arr[j] / base) % 10;
      t[pre[cur] - 1] = x;
      pre[cur]--;
    }
    std::swap(arr, t);
  }
}

}  // namespace algorithm_template