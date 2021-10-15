#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();

    int answer = INT_MAX;

    int sum = nums[0], s = 0, f = 1;
    while (f <= n && s < f) {
      if (target <= sum) {
        answer = min(answer, f - s);
      }

      sum <= target &&f < n ? sum += nums[f++] : sum -= nums[s++];
    }

    return answer == INT_MAX ? 0 : answer;
  }
};
