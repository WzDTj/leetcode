#include <vector>

using namespace std;

class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();

    int answer = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((board[i][j] == 'X') && (i - 1 < 0 || board[i - 1][j] == '.') &&
            (j - 1 < 0 || board[i][j - 1] == '.'))
          answer++;
      }
    }

    return answer;
  }
};
