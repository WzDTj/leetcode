#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int countKDifference(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    int answer = 0;

    for (int num : nums) {
      answer += map.count(num + k) ? map[num + k] : 0;
      answer += map.count(num - k) ? map[num - k] : 0;
      ++map[num];
    }

    return answer;
  }
};
