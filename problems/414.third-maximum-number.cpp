#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> map;
    for (int num : nums)
      ++map[num];

    vector<int> answer(3, INT_MIN);
    unordered_map<int, int>::iterator it = map.begin();
    while (it != map.end()) {
      if (answer[0] < it->first) {
        answer[2] = answer[1];
        answer[1] = answer[0];
        answer[0] = it->first;
      } else if (answer[1] < it->first) {
        answer[2] = answer[1];
        answer[1] = it->first;
      } else if (answer[2] < it->first) {
        answer[2] = it->first;
      }

      ++it;
    }

    return 3 <= map.size() ? answer[2] : answer[0];
  }
};
