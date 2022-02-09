#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int findPairs(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    for (int num : nums) {
      ++map[num];
    }

    int answer = 0;
    for (auto [num, count] : map) {
      answer += k == 0 ? 2 <= count : map.count(num + k);
    }

    return answer;
  }
};
