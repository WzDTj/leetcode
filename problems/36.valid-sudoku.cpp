#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // 优化版本

  bool isValidSudoku(vector<vector<char>> &board) {
    int n = board.size();

    vector<vector<int>> row_vec(9, vector<int>(9, 0));
    vector<vector<int>> col_vec(9, vector<int>(9, 0));
    vector<vector<vector<int>>> box_vec(
        3, vector<vector<int>>(3, vector<int>(9, 0)));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.')
          continue;

        int target = board[i][j] - 49;

        if (row_vec[i][target] || col_vec[j][target] ||
            box_vec[i / 3][j / 3][target])
          return false;

        ++row_vec[i][target];
        ++col_vec[j][target];
        ++box_vec[i / 3][j / 3][target];
      }
    }

    return true;
  }

  // 原始版本

  bool isValidSudoku2(vector<vector<char>> &board) {
    int n = board.size();

    // check each rows
    for (int i = 0; i < n; ++i) {
      unordered_map<char, int> map;
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.')
          continue;
        if (!this->findAndInsert(map, board[i][j]))
          return false;
      }
    }

    // check each cols
    for (int i = 0; i < n; ++i) {
      unordered_map<char, int> map;
      for (int j = 0; j < n; ++j) {
        if (board[j][i] == '.')
          continue;
        if (!this->findAndInsert(map, board[j][i]))
          return false;
      }
    }

    // check each 3x3 sub-boxes
    for (int i = 0; i < n; i += 3) {
      for (int j = 0; j < n; j += 3) {
        unordered_map<char, int> map;
        for (int k = i; k < i + 3; ++k) {
          for (int l = j; l < j + 3; ++l) {
            if (board[k][l] == '.')
              continue;
            if (!this->findAndInsert(map, board[k][l]))
              return false;
          }
        }
      }
    }

    return true;
  }

private:
  bool findAndInsert(unordered_map<char, int> &map, int target) {
    auto it = map.find(target);
    if (it != map.end())
      return false;
    map.insert({target, 1});
    return true;
  }
};
