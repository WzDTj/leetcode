#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size();

    int answer = 0;

    int f = 0, s = 0;
    while (f <= n) {
      if (f == n || !nums[f]) {
        answer = max(answer, f - s);
        s = f + 1;
      }

      f++;
    }

    return answer;
  }
};
