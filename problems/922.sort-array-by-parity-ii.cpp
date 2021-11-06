#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int n = nums.size();
    int p = 0, q = 1;

    while (p < n && q < n) {
      while (p < n && nums[p] % 2 == 0)
        p += 2;
      while (q < n && nums[q] % 2 == 1)
        q += 2;

      if (n <= p || n <= q)
        return nums;

      swap(nums[p], nums[q]);
    }

    return nums;
  }
};
