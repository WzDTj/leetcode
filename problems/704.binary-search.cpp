#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      nums[m] < target ? l = m + 1 : r = m;
    }

    return l < n && nums[l] == target ? l : -1;
  }
};
