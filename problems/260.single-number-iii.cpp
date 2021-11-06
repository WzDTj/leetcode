#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // 位运算

  vector<int> singleNumber(vector<int> &nums) {
    int xor_result = 0;

    for (int num : nums)
      xor_result ^= num;

    int num1 = 0, num2 = 0;
    int group = xor_result == INT_MIN ? xor_result : -xor_result & xor_result;

    for (int num : nums)
      group &num ? num1 ^= num : num2 ^= num;

    return {num1, num2};
  }

  // 排序 + 遍历

  // vector<int> singleNumber(vector<int> &nums) {
  //   int n = nums.size();
  //
  //   sort(nums.begin(), nums.end());
  //   vector<int> answer;
  //
  //   int i = 0;
  //   while (i < n) {
  //     if (i == n - 1 || nums[i] != nums[i + 1])
  //       answer.push_back(nums[i]);
  //     else
  //       ++i;
  //
  //     ++i;
  //   }
  //
  //   return answer;
  // }

  // 哈希表

  // vector<int> singleNumber(vector<int> &nums) {
  //   unordered_map<int, int> map;
  //
  //   for (int num : nums)
  //     ++map[num];
  //
  //   vector<int> answer;
  //   unordered_map<int, int>::iterator it = map.begin();
  //   while (it != map.end()) {
  //     if (it->second == 1)
  //       answer.push_back(it->first);
  //
  //     it++;
  //   }
  //
  //   return answer;
  // }
};
