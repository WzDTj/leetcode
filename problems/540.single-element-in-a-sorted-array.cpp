#include <vector>

using namespace std;

class Solution {
public:
  // 二分查找优化

  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n - 1;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (m & 1)
        m--;

      nums[m] == nums[m + 1] ? l = m + 2 : r = m;
    }

    return nums[l];
  }

  // 二分查找

  // int singleNonDuplicate(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   int l = 0, r = n - 1;
  //   while (l < r) {
  //     int m = l + ((r - l) >> 1);
  //     if (m & 1 && nums[m - 1] == nums[m])
  //       l = m + 1;
  //     else if (!(m & 1) && nums[m] == nums[m + 1])
  //       l = m + 2;
  //     else
  //       r = m;
  //   }
  //
  //   return nums[l];
  // }

  // 线性扫描

  // int singleNonDuplicate(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   for (int i = 0; i < n - 1; i += 2) {
  //     if (nums[i] != nums[i + 1])
  //       return nums[i];
  //   }
  //
  //   return nums[n - 1];
  // }
};
