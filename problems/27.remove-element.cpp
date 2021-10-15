#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();

    int f = 0, s = 0;

    while (f < n) {
      if (nums[f] != val)
        swap(nums[f], nums[s++]);

      f++;
    }

    return s;
  }
};
