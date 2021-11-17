#include <vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n, 0));
    return dfs(memo, m, n, 0, 0);
  }

private:
  int dfs(vector<vector<int>> &memo, int m, int n, int current_row,
          int current_col) {
    if (current_row == m - 1 || current_col == n - 1)
      return 1;

    if (memo[current_row][current_col])
      return memo[current_row][current_col];

    memo[current_row][current_col] =
        dfs(memo, m, n, current_row + 1, current_col) +
        dfs(memo, m, n, current_row, current_col + 1);

    return memo[current_row][current_col];
  }
};
