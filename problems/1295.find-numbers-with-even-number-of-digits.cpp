#include <vector>

using namespace std;

class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int n = nums.size();

    int even = 0;

    for (int i = 0; i < n; ++i) {
      int tmp = nums[i];

      while (10 <= tmp)
        tmp /= 100;

      if (!tmp)
        ++even;
    }

    return even;
  }
};
