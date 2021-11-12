#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
  // 缩小边界

  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> answer;
    int top = 0, right = n - 1, left = 0, bottom = m - 1;

    while (true) {
      for (int i = left; i <= right; ++i)
        answer.push_back(matrix[top][i]);

      if (bottom < ++top)
        break;

      for (int i = top; i <= bottom; ++i)
        answer.push_back(matrix[i][right]);

      if (--right < left)
        break;

      for (int i = right; left <= i; --i)
        answer.push_back(matrix[bottom][i]);

      if (--bottom < top)
        break;

      for (int i = bottom; top <= i; --i)
        answer.push_back(matrix[i][left]);

      if (right < ++left)
        break;
    }

    return answer;
  }

  // 按层模拟 （真纯模拟路径)

  // vector<int> spiralOrder(vector<vector<int>> &matrix) {
  //   int m = matrix.size();
  //   int n = matrix[0].size();
  //
  //   vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  //   vector<int> answer;
  //
  //   int loop_count = 0;
  //   int current_direction = 0;
  //   vector<int> current_position = {0, 0};
  //
  //   while (loop_count < min(ceil((float)m / 2), ceil((float)n / 2))) {
  //
  //     int tmp_m = max(m - 2 * loop_count, 1);
  //     int tmp_n = max(n - 2 * loop_count, 1);
  //     int count =
  //         2 <= tmp_m && 2 <= tmp_n ? 2 * (tmp_m + tmp_n - 2) : tmp_m * tmp_n;
  //
  //     current_direction = 0;
  //     while (count--) {
  //       answer.push_back(matrix[current_position[0]][current_position[1]]);
  //
  //       if (!count)
  //         current_direction = 0;
  //
  //       for (int i = current_direction; i < 4; ++i) {
  //         vector<int> next_position = {
  //             current_position[0] + directions[i][0],
  //             current_position[1] + directions[i][1],
  //         };
  //
  //         if (loop_count <= next_position[0] &&
  //             loop_count <= next_position[1] &&
  //             next_position[0] < m - loop_count &&
  //             next_position[1] < n - loop_count) {
  //           current_direction = i;
  //           current_position = next_position;
  //           break;
  //         }
  //       }
  //     }
  //
  //     ++loop_count;
  //   }
  //
  //   return answer;
  // }
};
