#include <vector>

using namespace std;

class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int n = nums.size();

    int max_idx = 0;
    for (int i = 0; i < n; ++i)
      if (nums[max_idx] < nums[i])
        max_idx = i;

    for (int i = 0; i < n; ++i)
      if (i != max_idx && nums[max_idx] < 2 * nums[i])
        return -1;

    return max_idx;
  }
};
