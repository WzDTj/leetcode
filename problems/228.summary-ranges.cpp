#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    int n = nums.size();

    vector<string> answer;

    int l = 0, r = 1;
    while (r <= n) {
      if (r == n || nums[r - 1] + 1 != nums[r]) {
        string range = l == r - 1
                           ? to_string(nums[l])
                           : to_string(nums[l]) + "->" + to_string(nums[r - 1]);

        answer.push_back(range);
        l = r;
      }
      ++r;
    }

    return answer;
  }
};
