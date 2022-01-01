#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
    int size = original.size();

    if (m * n != size) {
      return vector<vector<int>>();
    }

    vector<vector<int>> answer(m, vector<int>(n, 0));

    for (int i = 0; i < size; ++i) {
      answer[i / n][i % n] = original[i];
    }

    return answer;
  }
};
