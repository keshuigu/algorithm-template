#include "algorithm_template/tree.h"

#include "algorithm_template/validator.h"
#include "gtest/gtest.h"
namespace algorithm_template {
TEST(TreeTest, LevelOrderTraversalTest) {
  std::vector<int> tree{1, -1, 2, 3};
  auto root = ConstructTree(tree);
  std::vector<std::vector<int>> res;
  res.push_back({1});
  res.push_back({2});
  res.push_back({3});
  ASSERT_EQ(LevelOrderTraversal(root), res);
}

TEST(TreeTest, InorderTraversalTest) {
  std::vector<int> tree{1, -1, 2, 3};
  auto root = ConstructTree(tree);
  std::vector<int> res{1,3,2};
  ASSERT_EQ(InorderTraversal(root), res);
}

TEST(TreeTest, PreorderTraversalTest) {
  std::vector<int> tree{1, -1, 2, 3};
  auto root = ConstructTree(tree);
  std::vector<int> res{1,2,3};
  ASSERT_EQ(PreorderTraversal(root), res);
}

TEST(TreeTest, PostorderTraversalTest) {
  std::vector<int> tree{1, -1, 2, 3};
  auto root = ConstructTree(tree);
  std::vector<int> res{3,2,1};
  ASSERT_EQ(PostorderTraversal(root), res);
}

}  // namespace algorithm_template