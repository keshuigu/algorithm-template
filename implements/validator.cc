#include "algorithm_template/validator.h"

#include <cassert>
#include <cstdint>
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

std::vector<int> RandomNoRepeatArray(int n, int v) {
  assert(v >= n);
  std::unordered_set<int> seen;
  std::vector<int> arr(n);
  std::random_device rd;   // 用于生成种子
  std::mt19937 gen(rd());  // 使用 Mersenne Twister 作为随机数引擎
  std::uniform_int_distribution<> dis(1, v);  // 生成 [1, v] 范围内的随机数
  for (size_t i = 0; i < arr.size(); i++) {
    int x = dis(gen);
    while (seen.contains(x)) {
      x = dis(gen);
    }
    arr[i] = x;
    seen.insert(x);
  }
  return arr;
}

bool ValidExist(const std::vector<int>& arr, int x) {
  for (auto&& t : arr) {
    if (t == x) {
      return true;
    }
  }
  return false;
}
int ValidFindLeft(const std::vector<int>& arr, int x) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] >= x) {
      return i;
    }
  }
  return arr.size();
}
int ValidFindRight(const std::vector<int>& arr, int x) {
  for (int i = arr.size() - 1; i >= 0; i--) {
    if (arr[i] <= x) {
      return i;
    }
  }
  return -1;
}

std::unordered_set<int> ValidFindPeak(const std::vector<int>& arr) {
  std::unordered_set<int> ans;
  if (arr.size() <= 1) {
    ans.insert(0);
    return ans;
  }

  std::vector<int> vec(arr.size() + 2);
  vec[0] = INT32_MIN;
  vec[vec.size() - 1] = INT32_MIN;
  for (int i = 0; i < arr.size(); i++) {
    vec[i + 1] = arr[i];
  }
  for (int i = 1; i < vec.size() - 1; i++) {
    if (vec[i - 1] < vec[i] && vec[i] > vec[i + 1]) {
      ans.insert(i - 1);
    }
  }
  return ans;
}

BiTreeNode<int>* ConstructTree(std::vector<int> input) {
  if (input.empty()) {
    return nullptr;
  }
  BiTreeNode<int>* root = new BiTreeNode<int>(input[0]);
  std::vector<BiTreeNode<int>*> q;
  std::vector<BiTreeNode<int>*> t;
  q.push_back(root);
  int i = 1;
  while (i < input.size()) {
    for (int j = 0; j < q.size(); j++) {
      BiTreeNode<int>* x = q[j];
      if (i >= input.size()) {
        break;
      }
      if (input[i] != -1) {
        x->left = new BiTreeNode<int>(input[i]);
        t.push_back(x->left);
      }
      i++;
      if (i >= input.size()) {
        break;
      }
      if (input[i] != -1) {
        x->right = new BiTreeNode<int>(input[i]);
        t.push_back(x->right);
      }
      i++;
    }
    q.clear();
    std::swap(q, t);
  }
  return root;
}
}  // namespace algorithm_template
