#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (!n)
      return 0;

    int l = 1, r = 1;

    while (r < n) {
      if (nums[l - 1] < nums[r]) {
        swap(nums[l], nums[r]);
        l++;
      }

      r++;
    }

    return l;
  }
};
