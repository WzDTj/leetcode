#include <unordered_map>
#include <vector>

using namespace std;

// 哈希

class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int n = nums.size();
    int answer = 0;
    unordered_map<int, int> map;
    for (int b = n - 3; 0 <= b; --b) {
      for (int d = b + 2; d < n; ++d) {
        ++map[nums[d] - nums[b + 1]];
      }
      for (int a = 0; a < b; ++a) {
        answer += map[nums[a] + nums[b]];
      }
    }

    return answer;
  }
};

// 深搜

// class Solution {
// public:
//   int countQuadruplets(vector<int> &nums) { return dfs(nums, 0, 0, 0); }
//
// private:
//   int dfs(vector<int> &nums, int position, int level, int sum) {
//     int count = 0;
//
//     for (int i = position; i < nums.size(); ++i) {
//       if (level < 3) {
//         count += dfs(nums, i + 1, level + 1, sum + nums[i]);
//       } else if (nums[i] == sum) {
//         ++count;
//       }
//     }
//
//     return count;
//   }
// };
