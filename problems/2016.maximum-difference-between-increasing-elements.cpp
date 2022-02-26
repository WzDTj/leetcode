#include <vector>

using namespace std;

// 顺序遍历

class Solution {
public:
  int maximumDifference(vector<int> &nums) {
    int answer = -1;
    int min_num = nums[0];

    for (auto num : nums) {
      min_num < num ? answer = max(answer, num - min_num) : min_num = num;
    }

    return answer;
  }
};

// 逆序遍历

// class Solution {
// public:
//   int maximumDifference(vector<int> &nums) {
//     int n = nums.size();
//
//     int answer = 0, max_num = nums[n - 1];
//
//     for (int i = n - 1; 0 <= i; --i) {
//       max_num = max(max_num, nums[i]);
//       answer = max(answer, max_num - nums[i]);
//     }
//
//     return answer ? answer : -1;
//   }
// };
