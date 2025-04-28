#include "algorithm_template/sort.h"

#include <algorithm>
#include <random>
#include <vector>

#include "algorithm_template/validator.h"
#include "gtest/gtest.h"

namespace algorithm_template {
// 用validator验证排序
TEST(SortTest, SimpleSortTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, N - 1);
  for (int i = 0; i < epoch; i++) {
    int n = dis(gen);
    std::vector<int> a1 = RandomArray(n, V);
    std::vector<int> a2 = CopyArray(a1);
    std::vector<int> a3 = CopyArray(a1);
    std::vector<int> a4 = CopyArray(a1);
    std::vector<int> a5 = CopyArray(a1);
    std::vector<int> a6 = CopyArray(a1);
    SelectSort(a1);
    BubbleSort(a2);
    InsertSort(a3);
    MergeSort(a5);
    MergeSortNoRecursion(a6);
    std::sort(a4.begin(), a4.end());
    ASSERT_EQ(a1, a2) << "epoch " << i << " failed";
    ASSERT_EQ(a1, a3) << "epoch " << i << " failed";
    ASSERT_EQ(a1, a4) << "epoch " << i << " failed";
    ASSERT_EQ(a1, a5) << "epoch " << i << " failed";
    ASSERT_EQ(a1, a6) << "epoch " << i << " failed";
  }
}

}  // namespace algorithm_template