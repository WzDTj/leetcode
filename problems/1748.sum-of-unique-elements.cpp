#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int sumOfUnique(vector<int> &nums) {
    unordered_map<int, int> map;

    for (int &num : nums) {
      ++map[num];
    }

    int answer = 0;
    for (auto [num, count] : map) {
      if (count == 1) {
        answer += num;
      }
    }

    return answer;
  }
};
