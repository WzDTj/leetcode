#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int m = isWater.size();
    int n = isWater[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j] == 1) {
          q.emplace(i, j);
          isWater[i][j] = 0;
        } else {
          isWater[i][j] = -1;
        }
      }
    }

    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      for (auto [dy, dx] : directions) {
        if ((0 <= x + dx && x + dx < n) && (0 <= y + dy && y + dy < m) &&
            isWater[y + dy][x + dx] == -1) {
          isWater[y + dy][x + dx] = isWater[y][x] + 1;
          q.emplace(y + dy, x + dx);
        }
      }
    }

    return isWater;
  }
};
