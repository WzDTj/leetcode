#include "../structures/list_node.cpp"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    int n = 0;
    ListNode *current = head;
    while (current != nullptr) {
      current = current->next;
      ++n;
    }

    current = head;
    n >>= 1;

    while (n) {
      current = current->next;
      --n;
    }

    return current;
  }
};
