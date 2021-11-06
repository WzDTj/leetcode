#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int n = nums.size();

    int answer = (n * n + n) >> 1;

    for (int num : nums)
      answer -= num;

    return answer;
  }
};
