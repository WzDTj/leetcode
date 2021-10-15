#include <vector>

using namespace std;

class Solution {
public:
  // 双指针优化

  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();

    int l = 0, r = n - 1;

    while (l <= r) {
      nums[l] == val ? nums[l] = nums[r--] : l++;
    }

    return l;
  }

  // 快慢指针

  // int removeElement(vector<int> &nums, int val) {
  //   int n = nums.size();
  //
  //   int f = 0, s = 0;
  //
  //   while (f < n) {
  //     if (nums[f] != val)
  //       swap(nums[f], nums[s++]);
  //
  //     f++;
  //   }
  //
  //   return s;
  // }
};
