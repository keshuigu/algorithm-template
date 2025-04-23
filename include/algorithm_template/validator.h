#ifndef ALGORITHM_TEMPLATE_VALIDATOR_H
#define ALGORITHM_TEMPLATE_VALIDATOR_H
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include "algorithm_template/common.h"
#include "algorithm_template/tree.h"

namespace algorithm_template {

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

// tree

// 接受数组形式的树，生成一个树，返回树的根节点
// 数组可以近似以层的形式理解，只会包含非空节点以及其子结点(子结点可空，以-1表示)
// 最后一层叶节点后无后续输入
BiTreeNode<int>* ConstructTree(std::vector<int> input) ;
}  // namespace algorithm_template
#endif  // ALGORITHM_TEMPLATE_VALIDATOR_H
