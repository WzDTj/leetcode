#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();

    int sum = 0;
    for (int num : nums) {
      sum += num;
    }

    unordered_map<int, bool> memo;

    return sum % 2 ? false : dfs(memo, nums, 0, sum / 2);
  }

private:
  bool dfs(unordered_map<int, bool> &memo, vector<int> &nums, int current,
           int target) {
    int n = nums.size();

    if (target == 0)
      return true;
    else if (target < 0)
      return false;
    else if (n <= current)
      return false;
    else if (memo.count(target))
      return memo[target];

    memo[target] = dfs(memo, nums, current + 1, target - nums[current]) ||
                   dfs(memo, nums, current + 1, target);

    return memo[target];
  }
};
