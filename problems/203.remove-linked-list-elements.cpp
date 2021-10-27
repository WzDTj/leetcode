#include "../structures/list_node.cpp"

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *guard = new ListNode(-1, head);
    ListNode *current = guard;

    while (current->next != nullptr) {
      if (current->next->val == val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }

    return guard->next;
  }
};
