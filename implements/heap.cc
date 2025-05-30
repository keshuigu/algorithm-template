#include "algorithm_template/heap.h"

#include <algorithm>
#include <queue>
namespace algorithm_template {

// 差分
int MaxCover(const std::vector<std::vector<int>> lines) {
  // range 1 - 10**5
  std::vector<int> diff(100001);
  for (int i = 0; i < lines.size(); i++) {
    int x = lines[i][0];
    int y = lines[i][1];
    diff[x] += 1;
    diff[y] -= 1;
  }
  int ans = 0;
  int pre = 0;
  for (int i = 0; i < diff.size(); i++) {
    pre += diff[i];
    ans = std::max(ans, pre);
  }
  return ans;
}
int MaxCoverWithHeap(std::vector<std::vector<int>> lines) {
  std::sort(lines.begin(), lines.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
            });
  Heap<int, std::greater<int>> h;
  int ans = 0;
  for (int i = 0; i < lines.size(); i++) {
    while (!h.Empty() && h.Top() <= lines[i][0]) {
      h.Pop();
    }
    h.Push(lines[i][1]);
    ans = std::max(ans, static_cast<int>(h.Size()));
  }
  return ans;
}

int HalveArray(std::vector<int>& nums) {
  long long um = 0;
  Heap<double> h;
  for (auto&& x : nums) {
    um += x;
    h.Push(static_cast<double>(x));
  }
  int ans = 0;
  double cur = 0;
  double umf = static_cast<double>(um);
  while (cur * 2 < um) {
    double x = h.Top().value();
    cur += x / 2;
    ans++;
    h.Pop();
    h.Push(x / 2);
  }
  return ans;
}
}  // namespace algorithm_template