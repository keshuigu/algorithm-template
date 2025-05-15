#include "algorithm_template/heap.h"

#include <algorithm>
#include <queue>
#include <random>
#include <vector>

#include "algorithm_template/validator.h"
#include "gtest/gtest.h"
namespace algorithm_template {
TEST(HeapTest, MyHeapTest) {
  int N = 100;
  int V = 1000;
  int epoch = 50000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, N - 1);
  std::uniform_int_distribution<> disB(0, 1);
  for (int i = 0; i < epoch; i++) {
    int n = dis(gen);
    std::vector<int> a1 = RandomArray(n, V);
    Heap<int> h1;
    Heap<int> h2;
    std::priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      h1.Push(a1[i]);
      h2.Push(a1[i]);
      pq.push(a1[i]);
      if (disB(gen)) {
        auto x = h1.Top();
        ASSERT_TRUE(x.has_value());
        ASSERT_EQ(x.value(), pq.top());
      }
      if (!pq.empty() && disB(gen)) {
        pq.pop();
        h1.Pop();
      }
    }
    while (!pq.empty()) {
      auto x1 = h1.Top();
      ASSERT_TRUE(x1.has_value());
      ASSERT_EQ(x1.value(), pq.top());
      h1.Pop();
      pq.pop();
    }
    Heap<int> h3(std::move(a1));
    for (int i = 0; i < n; i++)
    {
      auto x1 = h2.Top();
      auto x2 = h3.Top();
      ASSERT_TRUE(x1.has_value());
      ASSERT_TRUE(x2.has_value());
      ASSERT_EQ(x1.value(), x2.value());
      h2.Pop();
      h3.Pop();
    }

  }
}

}  // namespace algorithm_template