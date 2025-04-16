#ifndef ALGORITHM_TEMPLATE_VALIDATOR_
#define ALGORITHM_TEMPLATE_VALIDATOR_
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

namespace algorithm_template {

template <typename T>
concept Streamable = requires(std::ostream& os, T t) {
  { os << t } -> std::convertible_to<std::ostream&>;
};

// 打印vector<int>内容
template <Streamable T>
std::string VectorToString(std::vector<T>& arr) {
  std::ostringstream oss;
  oss << "[";
  for (auto&& x : arr) {
    oss << x << ", ";
  }
  oss << "]";
  return oss.str();
}

//  返回一个长度为n,值域为[1,v]的随机数组
std::vector<int> RandomArray(int n, int v);

//  返回一个长度为n,值域为[1,v]的随机不重复数组
//  需求: v >= n
std::vector<int> RandomNoRepeatArray(int n, int v);

//  拷贝数组
inline std::vector<int> CopyArray(const std::vector<int> arr) {
  return std::vector<int>(arr.begin(), arr.end());
}

// bisect
bool ValidExist(const std::vector<int>& arr, int x);
int ValidFindLeft(const std::vector<int>& arr, int x);
int ValidFindRight(const std::vector<int>& arr, int x);
std::unordered_set<int> ValidFindPeak(const std::vector<int>& arr);
}  // namespace algorithm_template
#endif
