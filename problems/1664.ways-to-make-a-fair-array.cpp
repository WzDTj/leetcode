#include <vector>

using namespace std;

class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int n = nums.size();
    int answer = 0;
    int prefix_odd = 0, suffix_odd = 0;
    int prefix_even = 0, suffix_even = 0;

    for (int i = 0; i < n; ++i) {
      i & 1 ? suffix_odd += nums[i] : suffix_even += nums[i];
    }

    for (int i = 0; i < n; ++i) {
      i & 1 ? suffix_odd -= nums[i] : suffix_even -= nums[i];

      answer += (prefix_odd + suffix_even == prefix_even + suffix_odd);

      i & 1 ? prefix_odd += nums[i] : prefix_even += nums[i];
    }

    return answer;
  }
};
