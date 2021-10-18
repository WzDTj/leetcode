#include <vector>

using namespace std;

class Solution {
public:
  // 左闭右闭

  // int findMin(vector<int> &nums) {
  //   int n = nums.size();
  //   int l = 0, r = n - 1, target = n - 1;
  //
  //   while (l < r) {
  //     int m = l + ((r - l) >> 1);
  //     nums[m] < nums[n - 1] ? r = m : l = m + 1;
  //   }
  //
  //   return nums[l];
  // }

  // 左闭右开

  int findMin(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n, target = n - 1;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      nums[target] < nums[m] ? l = m + 1 : r = m;
    }

    return nums[l];
  }
};
