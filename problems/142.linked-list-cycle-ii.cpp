#include "../structures/list_node.cpp"

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr) {
      if (fast->next == nullptr) {
        return nullptr;
      }

      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) {
        fast = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return fast;
      }
    }

    return nullptr;
  }
};
