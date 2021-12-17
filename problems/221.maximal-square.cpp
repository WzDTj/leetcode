#include <vector>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> int_matrix(m + 1, vector<int>(n + 1, 0));

    int length = 0;

    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (matrix[i - 1][j - 1] == '0')
          continue;

        int top = int_matrix[i - 1][j];
        int left = int_matrix[i][j - 1];
        int top_left = int_matrix[i - 1][j - 1];

        int_matrix[i][j] = min(top, min(left, top_left)) + 1;
        length = max(length, int_matrix[i][j]);
      }
    }

    return length * length;
  }
};
