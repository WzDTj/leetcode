#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = 0;

    while (r < n) {
      if (nums[r]) {
        swap(nums[r], nums[l]);
        l++;
      }
      r++;
    }
  }
};
