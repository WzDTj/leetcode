#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int product = 1;
    int zero_count = 0;

    for (int num : nums) {
      if (num)
        product *= num;
      else
        ++zero_count;
    }

    if (2 <= zero_count)
      for (int &num : nums)
        num = 0;
    else if (zero_count == 1)
      for (int &num : nums)
        num = num ? 0 : product;
    else
      for (int &num : nums)
        num = product / num;

    return nums;
  }
};
