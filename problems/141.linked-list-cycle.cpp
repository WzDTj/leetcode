#include "../structures/list_node.cpp"
#include <climits>

class Solution {
public:
  // 利用数据范围

  bool hasCycle(ListNode *head) {
    while (head != nullptr) {
      if (head->val == INT_MIN)
        return true;
      head->val = INT_MIN;
      head = head->next;
    }

    return false;
  }
};
