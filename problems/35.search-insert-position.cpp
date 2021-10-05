#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size();

    while (l < r) {
      int m = l + ((r - l) >> 1);
      target <= nums[m] ? r = m : l = m + 1;
    }

    return l;
  }
};
