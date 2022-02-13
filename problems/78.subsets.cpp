#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> answer;

    answer.push_back({});

    for (auto num : nums) {
      int n = answer.size();
      for (int i = 0; i < n; ++i) {
        vector<int> tmp = vector<int>(answer[i]);
        tmp.push_back(num);
        answer.push_back(tmp);
      }
    }

    return answer;
  }
};
