#include "algorithm_template/divide_conquer.h"

#include <algorithm>
#include <random>
#include <vector>

#include "algorithm_template/validator.h"
#include "gtest/gtest.h"
namespace algorithm_template {

TEST(DivideConquerTest, SmallSumTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, N - 1);
  for (int i = 0; i < epoch; i++) {
    int n = dis(gen);
    std::vector<int> a1 = RandomArrayWithNeg(n, V);
    long long expect = ValidSmallSum(a1);
    long long ret = SmallSum(a1);
    ASSERT_EQ(expect, ret);
  }
}

TEST(DivideConquerTest, ReversePairsTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, N - 1);
  for (int i = 0; i < epoch; i++) {
    int n = dis(gen);
    std::vector<int> a1 = RandomArrayWithNeg(n, V);
    int expect = ValidReversePairs(a1);
    int ret = ReversePairs(a1);
    ASSERT_EQ(expect, ret);
  }
}

TEST(DivideConquerTest, FindKthLargestTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, N - 1);
  for (int i = 0; i < epoch; i++) {
    int n = dis(gen);
    std::vector<int> a1 = RandomArrayWithNeg(n, V);

    std::uniform_int_distribution<> disK(0, n - 1);
    int k = disK(gen);
    int expect = VaidFindKthLargest(a1, k);
    int ret = FindKthLargest(a1, k);
    ASSERT_EQ(expect, ret);
  }
}

}  // namespace algorithm_template