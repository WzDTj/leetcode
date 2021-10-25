#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> answer;
    vector<int> result(n);
    this->dfs(answer, result, nums, 0, n);
    return answer;
  }

private:
  void dfs(vector<vector<int>> &answer, vector<int> &result,
           vector<int> &elements, int l, int size) {
    if (l == size) {
      answer.push_back(vector<int>(result));
      return;
    }

    for (int i = 0; i < size; ++i) {
      if (elements[i] == INT_MIN)
        continue;

      int tmp = elements[i];
      elements[i] = INT_MIN;
      result[l] = tmp;
      this->dfs(answer, result, elements, l + 1, size);
      elements[i] = tmp;
    }
  }
};
