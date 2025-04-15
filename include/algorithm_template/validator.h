#ifndef ALGORITHM_TEMPLATE_VALIDATOR_
#define ALGORITHM_TEMPLATE_VALIDATOR_
#include <vector>

namespace algorithm_template {

//  返回一个长度为n,值域为[1,v]的随机数组
std::vector<int> RandomArray(int n, int v);

//  拷贝数组
inline std::vector<int> CopyArray(const std::vector<int> arr) {
  return std::vector<int>(arr.begin(), arr.end());
}
}  // namespace algorithm_template
#endif
