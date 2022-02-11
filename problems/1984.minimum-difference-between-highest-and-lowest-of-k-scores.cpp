#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int answer = INT_MAX;
    for (int i = 0; i < n - k + 1; ++i) {
      answer = min(answer, nums[i + k - 1] - nums[i]);
    }

    return answer;
  }
};
