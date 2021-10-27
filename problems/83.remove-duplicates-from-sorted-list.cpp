#include "../structures/list_node.cpp"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)
      return head;

    ListNode *current = head;

    while (current->next != nullptr) {
      if (current->val == current->next->val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

    return head;
  }
};
