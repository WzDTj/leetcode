#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int n = nums.size();

    int answer = 0;
    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (int num : nums)
        sum += num >> i & 1;

      if (sum % 3)
        answer |= 1 << i;
    }

    return answer;
  }
};
