#include <vector>

using namespace std;

class Solution {
public:
  // 前缀和

  int minStartValue(vector<int> &nums) {
    int sum = 0, min_sum = 1;

    for (int num : nums) {
      sum += num;
      min_sum = min(min_sum, sum);
    }

    return min_sum < 0 ? 1 - min_sum : min_sum;
  }

  // 二分查找

  // int minStartValue(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   int l = 0, r = 10001;
  //
  //   while (l < r) {
  //     int m = l + ((r - l) >> 1);
  //     valid(nums, m) < 1 ? l = m + 1 : r = m;
  //   }
  //
  //   return l;
  // }

private:
  // int valid(vector<int> &nums, int m) {
  //   int sum = m;
  //   int result = m;
  //
  //   for (int num : nums) {
  //     sum += num;
  //     result = min(result, sum);
  //   }
  //
  //   return result;
  // }
};
