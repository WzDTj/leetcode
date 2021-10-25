#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // 哈希表
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();

    unordered_map<int, int> map = unordered_map<int, int>();

    for (int i = 0; i < n; ++i) {
      unordered_map<int, int>::iterator it = map.find(target - nums[i]);
      if (it != map.end())
        return {it->second, i};

      map.insert({nums[i], i});
    }
    return {};
  }

  // 排序双指针

  // vector<int> twoSum(vector<int> &nums, int target) {
  //   int n = nums.size();
  //
  //   vector<int> answer(2);
  //   vector<int> sorted_nums = vector<int>(nums);
  //   sort(sorted_nums.begin(), sorted_nums.end());
  //
  //   int l = 0, r = n - 1;
  //   while (l < r) {
  //     int sum = sorted_nums[l] + sorted_nums[r];
  //     if (sum < target)
  //       ++l;
  //     else if (target < sum)
  //       --r;
  //     else
  //       break;
  //   }
  //
  //   for (int i = 0, j = 0; i < n; ++i) {
  //     if (nums[i] != sorted_nums[l] && nums[i] != sorted_nums[r])
  //       continue;
  //
  //     answer[j++] = i;
  //
  //     if (j == 2)
  //       return answer;
  //   }
  //
  //   return {};
  // }
};
