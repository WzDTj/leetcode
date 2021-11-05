#include <vector>

using namespace std;

class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    int n = arr.size();

    if (n < 3)
      return false;

    int l = 1, r = n - 2;
    while (l < n && arr[l - 1] < arr[l])
      ++l;
    while (0 <= r && arr[r + 1] < arr[r])
      --r;

    if (l == 1 || r == n - 2)
      return false;

    --l;
    ++r;

    return l == r;
  }
};
