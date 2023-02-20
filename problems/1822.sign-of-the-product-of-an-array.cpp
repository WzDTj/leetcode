#include <vector>

using namespace std;

class Solution {
public:
  int arraySign(vector<int> &nums) {
    int answer = 1;

    for (auto num : nums) {
      if (num == 0) {
        return 0;
      }

      answer *= num < 0 ? -1 : 1;
    }

    return answer;
  }
};
