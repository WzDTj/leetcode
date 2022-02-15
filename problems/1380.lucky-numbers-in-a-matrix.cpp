#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_map<int, int> map;

    for (int i = 0; i < m; ++i) {
      int small = matrix[i][0];
      int col = 0;
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] < small) {
          small = matrix[i][j];
          col = j;
        }
      }

      if (!map.count(col) || map[col] < small) {
        map[col] = small;
      }
    }

    vector<int> answer;
    for (auto [col, num] : map) {
      bool is_lucky_number = true;
      for (int i = 0; i < m; ++i) {
        if (num < matrix[i][col]) {
          is_lucky_number = false;
          break;
        }
      }
      if (is_lucky_number) {
        answer.push_back(num);
      }
    }

    return answer;
  }
};
