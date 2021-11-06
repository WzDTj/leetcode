#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;

    while (l < r) {
      if (nums[l] % 2)
        swap(nums[l], nums[r--]);
      else
        ++l;
    }

    return nums;
  }
};
