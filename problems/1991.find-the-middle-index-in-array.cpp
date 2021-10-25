#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int findMiddleIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int lsum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (sum == lsum * 2 + nums[i]) {
        return i;
      }
      lsum += nums[i];
    }

    return -1;
  }
};
