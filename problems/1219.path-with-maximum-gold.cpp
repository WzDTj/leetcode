#include <vector>

using namespace std;

class Solution {
  vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  int getMaximumGold(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    pair<int, int> size{m, n};

    int answer = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        int gold = dfs(grid, size, i, j);
        answer = max(answer, gold);
      }
    }

    return answer;
  }

private:
  int dfs(vector<vector<int>> &grid, pair<int, int> &size, int y, int x) {
    int value = grid[y][x];
    grid[y][x] = 0;

    int max_gold = 0;
    for (auto [dy, dx] : directions) {
      int next_y = y + dy;
      int next_x = x + dx;

      if ((0 <= next_y && next_y < size.first) &&
          (0 <= next_x && next_x < size.second) && grid[next_y][next_x] != 0) {
        int gold = dfs(grid, size, next_y, next_x);
        max_gold = max(max_gold, gold);
      }
    }

    grid[y][x] = value;

    return max_gold + value;
  }
};
