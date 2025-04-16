#include "algorithm_template/bisect.h"

#include <algorithm>
#include <random>
#include <vector>

#include "algorithm_template/validator.h"
#include "gtest/gtest.h"

namespace algorithm_template {
// 用validator验证排序
TEST(BisectTest, ExistTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  for (int i = 0; i < epoch; i++) {
    int n = disN(gen);
    std::vector<int> a = RandomArray(n, V);
    std::sort(a.begin(), a.end());
    int target = disV(gen);
    ASSERT_EQ(Exist(a, target), ValidExist(a, target));
  }
}

TEST(BisectTest, FindLeftTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  for (int i = 0; i < epoch; i++) {
    int n = disN(gen);
    std::vector<int> a = RandomArray(n, V);
    std::sort(a.begin(), a.end());
    int target = disV(gen);
    ASSERT_EQ(FindLeft(a, target), ValidFindLeft(a, target))
        << VectorToString(a) << target;
  }
}

TEST(BisectTest, FindRightTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  for (int i = 0; i < epoch; i++) {
    int n = disN(gen);
    std::vector<int> a = RandomArray(n, V);
    std::sort(a.begin(), a.end());
    int target = disV(gen);
    ASSERT_EQ(FindRight(a, target), ValidFindRight(a, target))
        << VectorToString(a) << target;
  }
}

TEST(BisectTest, FindPeekTest) {
  int N = 10;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  for (int i = 0; i < epoch; i++) {
    int n = disN(gen);
    std::vector<int> a = RandomNoRepeatArray(n, V);
    ASSERT_TRUE(ValidFindPeak(a).contains(FindPeak(a))) << VectorToString(a);
  }
}

}  // namespace algorithm_template