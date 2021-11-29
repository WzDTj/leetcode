#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      m + 1 < n &&nums[m] < nums[m + 1] ? l = m + 1 : r = m;
    }

    return l;
  }
};
