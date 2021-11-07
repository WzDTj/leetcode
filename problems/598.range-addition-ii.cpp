#include <vector>

using namespace std;

class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    int min_row = m, min_col = n;

    for (vector<int> &op : ops) {
      min_row = min(min_row, op[0]);
      min_col = min(min_col, op[1]);
    }

    return min_row * min_col;
  }
};
