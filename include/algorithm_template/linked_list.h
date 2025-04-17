#ifndef ALGORITHM_TEMPLATE_LINKED_LIST_
#define ALGORITHM_TEMPLATE_LINKED_LIST_
#include <concepts>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "algorithm_template/common.h"

namespace algorithm_template {
template <typename T>
struct LinkedList {
  T val;
  LinkedList* next;

  LinkedList(T val) : val(val), next(nullptr) {}
  LinkedList(T val, LinkedList* next) : val(val), next(next) {}
};

template <typename T>
struct DualLinkedList {
  T val;
  DualLinkedList* next;
  DualLinkedList* prev;

  DualLinkedList(T val) : val(val), next(nullptr), prev(nullptr) {}
};

template <Streamable T>
std::string LinkedListToString(LinkedList<T>* head) {
  if (head == nullptr) {
    return "";
  }
  std::stringstream ss;
  ss << head->val;
  head = head->next;
  while (head != nullptr) {
    ss << "->" << head->val;
    head = head->next;
  }
  return ss.str();
}

template <Streamable T>
std::string DualLinkedListToString(DualLinkedList<T>* head) {
  if (head == nullptr) {
    return "";
  }
  std::stringstream ss;
  ss << head->val;
  head = head->next;
  while (head != nullptr) {
    ss << "<->" << head->val;
    head = head->next;
  }
  return ss.str();
}

// https://leetcode.cn/problems/reverse-linked-list/description/
template <typename T>
LinkedList<T>* ReverseLinkedList(LinkedList<T>* head) {
  LinkedList<T>*p = head, *prev = nullptr, *q = nullptr;
  while (p != nullptr) {
    q = p->next;
    p->next = prev;
    prev = p;
    p = q;
  }
  return prev;
}

template <typename T>
DualLinkedList<T>* ReverseDualLinkedList(DualLinkedList<T>* head) {
  DualLinkedList<T>*p = head, *prev = nullptr, *q = nullptr;
  while (p != nullptr) {
    q = p->next;
    p->next = prev;
    p->prev = q;
    prev = p;
    p = q;
  }
  return prev;
}

//https://leetcode.cn/problems/merge-two-sorted-lists/description/
template <std::totally_ordered T>
LinkedList<T>* MergeTwoLists(LinkedList<T>* list1, LinkedList<T>* list2) {
  if (list1 == nullptr) {
    return list2;
  }
  if (list2 == nullptr) {
    return list1;
  }
  LinkedList<T>* dummy = new LinkedList<T>(list1->val);  // val无实际意义
  LinkedList<T>* p = dummy;
  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val <= list2->val) {
      p->next = list1;
      list1 = list1->next;
    } else {
      p->next = list2;
      list2 = list2->next;
    }
    p = p->next;
  }
  if (list1 != nullptr) {
    p->next = list1;
  } else if (list2 != nullptr) {
    p->next = list2;
  }
  p = dummy->next;
  delete dummy;
  return p;
}


// https://leetcode.cn/problems/merge-k-sorted-lists/description/
template <std::totally_ordered T>
LinkedList<T>* MergeKLists(std::vector<LinkedList<T>*>& lists) {
  auto greater = [](const LinkedList<T>* a, const LinkedList<T>* b) {
    return a->val > b->val;
  };
  std::priority_queue<LinkedList<T>*, std::vector<LinkedList<T>*>,
                      decltype(greater)>
      pq;
  LinkedList<T>* dummy = nullptr;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i] != nullptr) {
      if (dummy == nullptr) {
        dummy = new LinkedList<T>(lists[i]->val);
      }
      pq.push(lists[i]);
    }
  }
  if (dummy == nullptr) {
    return nullptr;
  }
  LinkedList<T>* q = dummy;
  LinkedList<T>* cur = nullptr;
  while (!pq.empty()) {
    cur = pq.top();
    pq.pop();

    q->next = cur;
    if (cur->next != nullptr) {
      pq.push(cur->next);
    }
    q = q->next;
  }

  LinkedList<T>* p = dummy->next;
  delete dummy;
  return p;
}
}  // namespace algorithm_template
#endif