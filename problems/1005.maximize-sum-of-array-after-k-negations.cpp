#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // 哈希表

  int largestSumAfterKNegations(vector<int> &nums, int k) {
    int n = nums.size();
    int answer = 0;

    unordered_map<int, int> map;

    for (int num : nums) {
      ++map[num];
      answer += num;
    }

    for (int i = -100; i < 0; ++i) {
      if (!map[i])
        continue;

      int count = min(k, map[i]);
      map[i] -= count;
      map[-i] += count;
      k -= count;
      answer -= count * i * 2;

      if (k == 0)
        break;
    }

    if (0 < k && k % 2 && !map[0]) {
      for (int i = 1; i <= 100; ++i) {
        if (map[i]) {
          answer -= i * 2;
          break;
        }
      }
    }

    return answer;
  }

  // 贪心

  // int largestSumAfterKNegations(vector<int> &nums, int k) {
  //   int n = nums.size();
  //
  //   sort(nums.begin(), nums.end());
  //
  //   int answer = 0;
  //
  //   int i = 0;
  //   while (i < n && 0 < k && nums[i] < 0) {
  //     answer += -nums[i];
  //     --k;
  //     ++i;
  //   }
  //
  //   if (k % 2) {
  //     answer += i == n || (0 < i && -nums[i - 1] < nums[i]) ? 2 * nums[i - 1]
  //                                                           : -nums[i++];
  //   }
  //
  //   while (i < n) {
  //     answer += nums[i++];
  //   }
  //
  //   return answer;
  // }
};
