#include "../structures/list_node.cpp"

class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *part1 = list1;
    ListNode *part2 = nullptr;

    int count = 1;

    while (count < a) {
      part1 = part1->next;
      count++;
    }

    part2 = part1->next;
    part1->next = list2;

    while (part1->next != nullptr) {
      part1 = part1->next;
    }

    while (count <= b) {
      part2 = part2->next;
      count++;
    }

    part1->next = part2;

    return list1;
  }
};
