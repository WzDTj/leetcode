#include <vector>

using namespace std;

class Solution {
public:
  // 翻转数组

  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    int step = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + step);
    reverse(nums.begin() + step, nums.end());
  }

  // 利用辅助数组

  // void rotate(vector<int> &nums, int k) {
  //   int n = nums.size();
  //   int step = k % n;
  //
  //   if (!step)
  //     return;
  //
  //   vector<int> tmp;
  //   for (int i = n - step; i < n; ++i)
  //     tmp.push_back(nums[i]);
  //
  //   for (int i = n - step - 1; 0 <= i; --i)
  //     nums[i + step] = nums[i];
  //
  //   for (int i = 0; i < step; ++i)
  //     nums[i] = tmp[i];
  // }

  // 原地交换

  // void rotate(vector<int> &nums, int k) {
  //   int n = nums.size();
  //   int step = k % n;
  //
  //   if (!step)
  //     return;
  //
  //   for (int i = 0, count = 0; count < n; ++i) {
  //     int j = i;
  //     int tmp = nums[i];
  //     while (j % n != i || i == j) {
  //       j += step;
  //       swap(nums[j % n], tmp);
  //       ++count;
  //     }
  //   }
  // }
};
