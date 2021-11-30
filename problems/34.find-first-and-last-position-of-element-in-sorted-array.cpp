#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int start = search(nums, target);
    if (!n || n <= start || nums[start] != target)
      return {-1, -1};

    int end = search(nums, target + 1) - 1;
    return {start, end};
  }

private:
  int search(vector<int> &nums, int target) {
    int n = nums.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      nums[m] < target ? l = m + 1 : r = m;
    }
    return l;
  }
};
