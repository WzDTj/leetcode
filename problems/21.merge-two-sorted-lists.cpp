#include "../structures/list_node.cpp"
#include <algorithm>

using namespace std;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(-1);
    ListNode *pre = head;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        pre->next = l1;
        l1 = l1->next;
      } else {
        pre->next = l2;
        l2 = l2->next;
      }

      pre = pre->next;
    }

    pre->next = l1 != nullptr ? l1 : l2;

    return head->next;
  }
};
