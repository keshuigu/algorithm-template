#include "algorithm_template/linked_list.h"

#include <cstdint>
#include <random>
#include <string>

#include "algorithm_template/validator.h"
#include "gtest/gtest.h"
namespace algorithm_template {

TEST(LinkedListTest, ReverseLinkedListTest) {
  int N = 100;
  int V = 1000;
  int epoch = 5000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  typedef LinkedList<int> IntList;
  for (int i = 0; i < epoch; i++) {
    IntList* head = new IntList(disV(gen));
    IntList* p = head;
    int n = disN(gen);
    for (size_t j = 0; j < n; j++) {
      p->next = new IntList(disV(gen));
      p = p->next;
    }
    std::string expect = LinkedListToString(head);
    ASSERT_EQ(expect,
              LinkedListToString(ReverseLinkedList(ReverseLinkedList(head))));
    while (head != nullptr) {
      p = head;
      head = head->next;
      delete p;
    }
  }
}

TEST(LinkedListTest, ReverseDualLinkedListTest) {
  int N = 100;
  int V = 1000;
  int epoch = 5000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  typedef DualLinkedList<int> DualIntList;
  for (int i = 0; i < epoch; i++) {
    DualIntList* head = new DualIntList(disV(gen));
    DualIntList* p = head;
    DualIntList* q = nullptr;
    int n = disN(gen);
    for (size_t j = 0; j < n; j++) {
      q = new DualIntList(disV(gen));
      q->prev = p;
      p->next = q;
      p = p->next;
    }
    std::string expect = DualLinkedListToString(head);
    ASSERT_EQ(expect, DualLinkedListToString(
                          ReverseDualLinkedList(ReverseDualLinkedList(head))));
    while (head != nullptr) {
      p = head;
      head = head->next;
      delete p;
    }
  }
}

TEST(LinkedListTest, MergeTwoListsTest) {
  int N = 100;
  int V = 1000;
  int epoch = 5000;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disV(0, 2 * V);
  typedef LinkedList<int> IntList;
  for (int i = 0; i < epoch; i++) {
    int n = disN(gen);
    std::vector<int> h1 = RandomArray(n, V);
    std::sort(h1.begin(), h1.end());
    IntList* head1 = n == 0 ? nullptr : new IntList(h1[0]);
    IntList* p = head1;
    for (int j = 0; j < n - 1; j++) {
      p->next = new IntList(h1[j + 1]);
      p = p->next;
    }
    n = disN(gen);
    std::vector<int> h2 = RandomArray(n, V);
    std::sort(h2.begin(), h2.end());
    IntList* head2 = n == 0 ? nullptr : new IntList(h2[0]);
    p = head2;
    for (int j = 0; j < n - 1; j++) {
      p->next = new IntList(h2[j + 1]);
      p = p->next;
    }
    IntList* head = MergeTwoLists(head1, head2);
    p = head;
    std::vector<int> result;
    while (p != nullptr) {
      result.push_back(p->val);
      p = p->next;
    }
    std::vector<int> expect;

    // 合并两个 vector
    expect.reserve(h1.size() + h2.size());  // 预留空间以避免多次分配
    expect.insert(expect.end(), h1.begin(), h1.end());
    expect.insert(expect.end(), h2.begin(), h2.end());

    // 排序
    std::sort(expect.begin(), expect.end());
    ASSERT_EQ(result, expect);
    while (head != nullptr) {
      p = head;
      head = head->next;
      delete p;
    }
  }
}

TEST(LinkedListTest, MergeKListsTest) {
  int N = 500;
  int K = 100;
  int V = 100;
  int epoch = 500;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> disN(0, N);
  std::uniform_int_distribution<> disK(0, K);
  typedef LinkedList<int> IntList;
  for (int i = 0; i < epoch; i++) {
    int k = disK(gen);
    std::vector<int> expect;
    std::vector<IntList*> lists(k);
    IntList* head =nullptr,*p = nullptr;
    for (int i = 0; i < k; i++) {
      int n = disN(gen);
      std::vector<int> h = RandomArray(n, V);
      std::sort(h.begin(), h.end());
      head = n == 0 ? nullptr : new IntList(h[0]);
      p = head;
      for (int j = 0; j < n - 1; j++) {
        p->next = new IntList(h[j + 1]);
        p = p->next;
      }
      lists[i] = head;
      expect.insert(expect.end(), h.begin(), h.end());
    }
    head = MergeKLists(lists);
    p = head;
    std::vector<int> result;
    while (p != nullptr) {
      result.push_back(p->val);
      p = p->next;
    }
    // 排序
    std::sort(expect.begin(), expect.end());
    ASSERT_EQ(result, expect);
    while (head != nullptr) {
      p = head;
      head = head->next;
      delete p;
    }
  }
}

}  // namespace algorithm_template
