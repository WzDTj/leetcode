#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    map[0] = 1;

    int answer = 0, sum = 0;
    for (int num : nums) {
      sum += num;

      if (map.count(sum - k)) {
        answer += map[sum - k];
      }

      ++map[sum];
    }

    return answer;
  }
};
