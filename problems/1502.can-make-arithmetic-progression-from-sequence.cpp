#include <vector>

using namespace std;

class Solution {
public:
  bool canMakeArithmeticProgression(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    int n = arr.size();

    int base = arr[0] - arr[1];

    for (int i = 2; i < n; ++i) {
      if (arr[i - 1] - arr[i] != base) {
        return false;
      }
    }

    return true;
  }
};
