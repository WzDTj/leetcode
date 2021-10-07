#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> rows(m), cols(n);

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0)
          rows[i] = cols[j] = true;
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; j++) {
        if (rows[i] || cols[j])
          matrix[i][j] = 0;
      }
    }
  }
};
