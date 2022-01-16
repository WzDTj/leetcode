#include "../structures/list_node.cpp"
#include <cmath>

class Solution {
  ListNode *head;

public:
  Solution(ListNode *head) { this->head = head; }

  int getRandom() {
    int answer = 0;

    ListNode *node = head;
    int i = 0;

    while (node != nullptr) {
      if (rand() % i == 0) {
        answer = node->val;
      }

      node = node->next;
      ++i;
    }

    return answer;
  }
};
