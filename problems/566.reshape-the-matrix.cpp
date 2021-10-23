#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();

    if (m * n != r * c)
      return mat;

    vector<vector<int>> answer(r, vector<int>(c, 0));

    for (int i = 0; i < m * n; ++i) {
      answer[i / c][i % c] = mat[i / n][i % n];
    }

    return answer;
  }
};
