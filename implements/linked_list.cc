#include "algorithm_template/linked_list.h"
namespace algorithm_template {
LinkedList<int>* AddTwoNumbers(LinkedList<int>* l1, LinkedList<int>* l2) {
  int c = 0;
  if (l1 == nullptr) {
    return l2;
  }
  if (l2 == nullptr) {
    return l1;
  }
  LinkedList<int>*head = l1, *prev = nullptr;
  LinkedList<int>* prev2 = nullptr;  // 方便后续delete 与算法无关；
  while (l1 != nullptr && l2 != nullptr) {
    int t = l1->val + l2->val + c;
    if (t >= 10) {
      t -= 10;
      c = 1;
    } else {
      c = 0;
    }
    l1->val = t;
    prev = l1;
    prev2 = l2;
    l1 = l1->next;
    l2 = l2->next;
  }
  if (l2 != nullptr){
    prev2->next = nullptr;  // l2 将链接到l1后端,此处置空防止重复delete
    prev->next = l2;
  }
  while (c) {
    if (prev->next == nullptr) {
      prev->next = new LinkedList<int>(1);
      break;
    } else {
      prev->next->val += 1;
      if (prev->next->val < 10) {
        break;
      } else {
        prev->next->val = 0;
        prev = prev->next;
      }
    }
  }
  return head;
}

}  // namespace algorithm_template
