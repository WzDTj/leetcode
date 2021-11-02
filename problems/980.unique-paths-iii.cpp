#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    int empty_squares = 0;
    vector<int> start_position;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!grid[i][j])
          ++empty_squares;
        if (grid[i][j] == 1)
          start_position = {i, j};
      }
    }

    grid[start_position[0]][start_position[1]] = 0;

    int answer = dfs(grid, start_position, empty_squares + 1);

    return answer;
  }

private:
  vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int dfs(vector<vector<int>> &grid, vector<int> position, int target_step) {
    if (!target_step && grid[position[0]][position[1]] == 2)
      return 1;
    if (grid[position[0]][position[1]] != 0)
      return 0;

    int count = 0;
    for (int i = 0; i < directions.size(); ++i) {
      vector<int> next_position{
          position[0] + directions[i][0],
          position[1] + directions[i][1],
      };

      if (next_position[0] < 0 || grid.size() <= next_position[0] ||
          next_position[1] < 0 || grid[0].size() <= next_position[1])
        continue;

      grid[position[0]][position[1]] = -1;
      count += dfs(grid, next_position, target_step - 1);
      grid[position[0]][position[1]] = 0;
    }

    return count;
  }
};
