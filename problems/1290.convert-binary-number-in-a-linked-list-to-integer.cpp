#include "../structures/list_node.cpp"
#include <cmath>

using namespace std;

class Solution {
public:
  // 优化一次遍历

  int getDecimalValue(ListNode *head) {
    int answer = 0;
    ListNode *current = head;
    while (current != nullptr) {
      answer = (answer << 1) + current->val;
      current = current->next;
    }

    return answer;
  }

  // 模拟

  // int getDecimalValue(ListNode *head) {
  //   int cnt = 0;
  //   ListNode *current = head;
  //   while (current != nullptr) {
  //     current = current->next;
  //     ++cnt;
  //   }
  //
  //   int answer = 0;
  //   current = head;
  //   while (current != nullptr) {
  //     --cnt;
  //     answer += current->val ? pow(2, cnt) : 0;
  //     current = current->next;
  //   }
  //
  //   return answer;
  // }
};
