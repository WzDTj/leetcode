#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  // 统计
  // void sortColors(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   vector<int> colors(3);
  //
  //   for (int i = 0; i < n; ++i)
  //     colors[nums[i]]++;
  //
  //   int i = 0, j = 0;
  //   while (i < n)
  //     0 < colors[j]-- ? nums[i++] = j : j++;
  // }

  // 三指针
  void sortColors(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0, l = 0, r = n - 1; i <= r; ++i) {
      switch (nums[i]) {
      case 0:
        swap(nums[i], nums[l++]);
        break;
      case 2:
        swap(nums[i--], nums[r--]);
        break;
      }
    }
  }
};
