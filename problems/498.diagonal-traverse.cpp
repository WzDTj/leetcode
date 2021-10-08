#include <atomic>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int directions[4][2] = {
        {-1, 1}, // top right
        {1, -1}, // bottom left
        {0, 1},  // right
        {1, 0},  // down
    };

    int m = mat.size();
    int n = mat[0].size();

    int row = 1, col = -1;

    vector<int> answer(m * n);
    vector<int>::iterator it = answer.begin();

    int last_direction = 0;

    while (it != answer.end()) {
      int current_direction;
      if (last_direction == 0) {
        if (0 <= row - 1 && col + 1 < n)
          current_direction = 0;
        else if (col + 1 < n)
          current_direction = 2;
        else
          current_direction = 3;
      } else if (last_direction == 1) {
        if (row + 1 < m && 0 <= col - 1)
          current_direction = 1;
        else if (row + 1 < m)
          current_direction = 3;
        else
          current_direction = 2;
      } else if (last_direction == 2) {
        if (row + 1 < m && 0 <= col - 1)
          current_direction = 1;
        else if (0 <= row - 1 && col + 1 < n)
          current_direction = 0;
        else
          current_direction = 2;
      } else if (last_direction == 3) {
        if (0 <= row - 1 && col + 1 < n)
          current_direction = 0;
        else if (row + 1 < m && 0 <= col - 1)
          current_direction = 1;
        else
          current_direction = 3;
      }

      row += directions[current_direction][0];
      col += directions[current_direction][1];
      *it++ = mat[row][col];

      last_direction = current_direction;
    }

    return answer;
  }
};
