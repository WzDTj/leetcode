#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> map;

    for (int i = 0; i < n; ++i) {
      if (map.count(nums[i]) && i - map[nums[i]] <= k) {
        return true;
      }

      map[nums[i]] = i;
    }

    return false;
  }
};
