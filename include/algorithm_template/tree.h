#ifndef ALGORITHM_TEMPLATE_TREE_H
#define ALGORITHM_TEMPLATE_TREE_H

#include <functional>
#include <vector>

namespace algorithm_template {

template <typename T>
struct BiTreeNode {
  T val;
  BiTreeNode* left;
  BiTreeNode* right;
  BiTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
  BiTreeNode(T x, BiTreeNode* left, BiTreeNode* right)
      : val(x), left(left), right(right) {}
};

// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
template <typename T>
std::vector<T> InorderTraversal(BiTreeNode<T>* root) {
  std::vector<T> ans;
  std::function<void(BiTreeNode<T>*)> dfs = [&](BiTreeNode<T>* root) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left);
    ans.push_back(root->val);
    dfs(root->right);
  };
  dfs(root);
  return ans;
}

// https://leetcode.cn/problems/binary-tree-postorder-traversal/
template <typename T>
std::vector<T> PostorderTraversal(BiTreeNode<T>* root) {
  std::vector<T> ans;
  std::function<void(BiTreeNode<T>*)> dfs = [&](BiTreeNode<T>* root) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left);
    dfs(root->right);
    ans.push_back(root->val);
  };
  dfs(root);
  return ans;
}

// https://leetcode.cn/problems/binary-tree-preorder-traversal/
template <typename T>
std::vector<T> PreorderTraversal(BiTreeNode<T>* root) {
  std::vector<T> ans;
  std::function<void(BiTreeNode<T>*)> dfs = [&](BiTreeNode<T>* root) {
    if (root == nullptr) {
      return;
    }
    ans.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
  };
  dfs(root);
  return ans;
}

// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
template <typename T>
std::vector<std::vector<T>> LevelOrderTraversal(BiTreeNode<T>* root) {
  if (root == nullptr) {
    return {};
  }
  std::vector<std::vector<T>> ret;
  std::vector<BiTreeNode<T>*> q;
  q.push_back(root);
  std::vector<BiTreeNode<T>*> t;
  while (!q.empty()) {
    std::vector<T> ans;
    for (int i = 0; i < q.size(); i++) {
      BiTreeNode<T>* x = q[i];
      ans.push_back(x->val);
      if (x->left != nullptr) {
        t.push_back(x->left);
      }
      if (x->right != nullptr) {
        t.push_back(x->right);
      }
    }
    ret.push_back(std::move(ans));
    q.clear();
    std::swap(q, t);
  }
  return ret;
}

}  // namespace algorithm_template

#endif  // ALGORITHM_TEMPLATE_TREE_H