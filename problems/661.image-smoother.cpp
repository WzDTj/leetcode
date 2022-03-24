#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int m = img.size();
    int n = img[0].size();

    vector<vector<int>> answer(m, vector<int>(n, 0));

    for (int i = 0; i < m * n; ++i) {
      int row = i / n;
      int col = i % n;

      int sum = 0;
      int count = 0;

      for (int j = 0; j < 9; ++j) {
        int s_row = j / 3 + row - 1;
        int s_col = j % 3 + col - 1;

        if (s_row < 0 || m <= s_row || s_col < 0 || n <= s_col) {
          continue;
        }
        sum += img[s_row][s_col];
        ++count;
      }

      answer[row][col] = sum / count;
    }

    return answer;
  }
};
