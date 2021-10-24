#include <vector>

using namespace std;

class Solution {
public:
  void duplicateZeros(vector<int> &arr) {
    int n = arr.size();

    int count = 0, valid_length = 0;
    while (count < n) {
      if (!arr[valid_length])
        ++count;
      ++count, ++valid_length;
    }

    if (n < count) {
      arr[--n] = 0;
      --valid_length;
    }

    for (int i = n - 1; 0 <= i; --i) {
      if (arr[valid_length - 1] != 0) {
        arr[i] = arr[--valid_length];
      } else {
        arr[i] = 0;
        arr[--i] = 0;
        --valid_length;
      }
    }
  }
};
