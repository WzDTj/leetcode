#include <vector>

using namespace std;

class Solution {
public:
  // 一次二分查找

  int search(vector<int> &nums, int target) {
    int n = nums.size();

    int l = 0, r = n;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      (nums[0] <= nums[m] &&
       ((target < nums[0]) || (nums[0] <= target && nums[m] < target))) ||
              (nums[m] < nums[0] && target < nums[0] && nums[m] < target)
          ? l = m + 1
          : r = m;
    }

    return l < n && nums[l] == target ? l : -1;
  }

  // 二次二分查找

  // int search(vector<int> &nums, int target) {
  //   int n = nums.size();
  //   int min_index = searchMinimum(nums);
  //
  //   int l = 0, r = n;
  //   nums[min_index] <= target &&target <= nums[n - 1] ? l = min_index
  //                                                     : r = min_index;
  //
  //   while (l < r) {
  //     int m = l + ((r - l) >> 1);
  //     nums[m] < target ? l = m + 1 : r = m;
  //   }
  //
  //   return nums[l] == target ? l : -1;
  // }

private:
  int searchMinimum(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      nums[n - 1] < nums[m] ? l = m + 1 : r = m;
    }

    return l;
  }
};
