#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer;

    for (int i = 0; i < numRows; i++) {
      vector<int> tmp;
      for (int j = 0; j < i + 1; j++) {
        j == 0 || j == i
            ? tmp.push_back(1)
            : tmp.push_back(answer[i - 1][j] + answer[i - 1][j - 1]);
      }
      answer.push_back(tmp);
    }

    return answer;
  }
};
