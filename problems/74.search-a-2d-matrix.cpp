#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int l = 0, r = m * n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      matrix[m / n][m % n] < target ? l = m + 1 : r = m;
    }

    return l < m * n && matrix[l / n][l % n] == target;
  }
};
