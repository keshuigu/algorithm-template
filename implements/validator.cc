#include "algorithm_template/validator.h"

#include <random>

namespace algorithm_template {
std::vector<int> RandomArray(int n, int v) {
  std::vector<int> arr(n);
  std::random_device rd;   // 用于生成种子
  std::mt19937 gen(rd());  // 使用 Mersenne Twister 作为随机数引擎
  std::uniform_int_distribution<> dis(1, v);  // 生成 [1, v] 范围内的随机数
  for (size_t i = 0; i < arr.size(); i++) {
    arr[i] = dis(gen);
  }
  return arr;
}
}  // namespace algorithm_template
