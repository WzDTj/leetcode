#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // 单调栈

  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> answer;

    unordered_map<int, int> map;
    stack<int> stk;

    for (int i = nums2.size() - 1; 0 <= i; --i) {
      while (!stk.empty() && stk.top() <= nums2[i]) {
        stk.pop();
      }

      map[nums2[i]] = stk.empty() ? -1 : stk.top();

      stk.push(nums2[i]);
    }

    for (auto num : nums1) {
      answer.emplace_back(map[num]);
    }

    return answer;
  }
};
