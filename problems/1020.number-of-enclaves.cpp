#include <vector>

using namespace std;

class Solution {
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  int numEnclaves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i) {
      dfs(grid, i, 0, m, n);
      dfs(grid, i, n - 1, m, n);
    }

    for (int i = 1; i < n - 1; ++i) {
      dfs(grid, 0, i, m, n);
      dfs(grid, m - 1, i, m, n);
    }

    int answer = 0;
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (grid[i][j] == 1) {
          ++answer;
        }
      }
    }

    return answer;
  }

private:
  void dfs(vector<vector<int>> &grid, int row, int col, int m, int n) {
    if (row < 0 || m <= row || col < 0 || n <= col || grid[row][col] == 0) {
      return;
    }

    grid[row][col] = 0;

    for (auto [dr, dc] : directions) {
      dfs(grid, row + dr, col + dc, m, n);
    }
  }
};
