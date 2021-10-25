#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // 左右翻转
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < (n >> 1); ++col) {
        swap(matrix[row][col], matrix[row][n - 1 - col]);
      }
    }

    // 斜对角翻转
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n - row; ++col) {
        swap(matrix[row][col], matrix[n - 1 - col][n - 1 - row]);
      }
    }
  }
};
