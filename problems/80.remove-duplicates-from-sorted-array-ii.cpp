#include <vector>

using namespace std;

class Solution {
public:
  // 有序数组，保留 k 位

  int removeDuplicates(vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
      return n;

    int l = 2, r = 2;

    while (r < n) {
      if (nums[l - 2] != nums[r])
        nums[l++] = nums[r];

      r++;
    }

    return l;
  }

  // 利用 count 计数
  //
  // int removeDuplicates(vector<int> &nums) {
  //   int n = nums.size();
  //   if (n < 2)
  //     return n;
  //
  //   int l = 1, r = 1, count = 1;
  //
  //   while (r < n) {
  //     nums[l - 1] == nums[r] ? count++ : count = 1;
  //
  //     if (nums[l - 1] <= nums[r] && count <= 2)
  //       nums[l++] = nums[r];
  //
  //     r++;
  //   }
  //
  //   return l;
  // }
};
