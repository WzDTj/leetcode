#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();

    int l = 0, r = n - 1;
    while (l < r) {
      int tmp = numbers[l] + numbers[r];
      if (tmp < target)
        l++;
      else if (target < tmp)
        r--;
      else
        return vector<int>{l + 1, r + 1};
    }

    return vector<int>();
  }
};
