#include "../structures/list_node.cpp"

class Solution {
public:
  // 递归

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *reversed = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return reversed;
  }

  // 迭代

  // ListNode *reverseList(ListNode *head) {
  //   ListNode *previous = nullptr;
  //   ListNode *current = head;
  //
  //   while (current != nullptr) {
  //     ListNode *tmp = current->next;
  //     current->next = previous;
  //     previous = current;
  //     current = tmp;
  //   }
  //
  //   return previous;
  // }
};
