#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // 哈希表

  int findLHS(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> map;

    for (int num : nums)
      ++map[num];

    int answer = 0;

    for (auto [num, count] : map) {
      if (map.count(num + 1)) {
        answer = max(answer, map[num] + map[num + 1]);
      }
    }

    return answer;
  }
};
