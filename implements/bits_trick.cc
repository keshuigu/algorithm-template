#include "algorithm_template/bits_trick.h"

#include <algorithm>
namespace algorithm_template {
std::string IntToBinaryString(int x) {
  std::string res;
  int len = sizeof(int) * 8;
  res.resize(len);
  for (int i = 0; i < len; i++) {
    res[i] = '0' + ((x >> i) & 1);
  }
  std::reverse(res.begin(), res.end());
  return res;
}
}  // namespace algorithm_template