#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n, target = n - 1;

    while (l < r && nums[l] == nums[n - 1])
      ++l;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      nums[target] < nums[m] ? l = m + 1 : r = m;
    }

    return nums[l % n];
  }
};
