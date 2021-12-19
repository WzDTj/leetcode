#include <vector>

using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<int> memo(n + 1, 0);

    for (vector<int> relation : trust) {
      memo[relation[0]]--;
      memo[relation[1]]++;
    }

    for (int i = 1; i < n + 1; ++i) {
      if (memo[i] == n - 1)
        return i;
    }

    return -1;
  }
};
