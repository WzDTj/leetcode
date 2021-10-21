#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  // 动态规划

  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    int pre = 0, answer = nums[0];

    for (int i = 0; i < n; ++i) {
      pre = max(nums[i], nums[i] + pre);
      answer = max(answer, pre);
    }

    return answer;
  }

  // 暴力枚举

  // int maxSubArray(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   int answer = INT_MIN;
  //
  //   vector<vector<int>> map(n, vector<int>(n, 0));
  //
  //   for (int i = 0; i < n; ++i) {
  //     map[i][i - 1] = 0;
  //     for (int j = i; j < n; ++j) {
  //       map[i][j] = map[i][j - 1] + nums[j];
  //       answer = max(answer, map[i][j]);
  //     }
  //   }
  //
  //   return answer;
  // }
};
