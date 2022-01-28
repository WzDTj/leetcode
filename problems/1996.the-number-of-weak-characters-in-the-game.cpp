#include <vector>

using namespace std;

bool compare(const vector<int> &lhs, const vector<int> &rhs) {
  return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : rhs[0] < lhs[0];
}

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    sort(properties.begin(), properties.end(), compare);

    int n = properties.size();

    int answer = 0;

    int max_defense = properties[0][1];

    for (int i = 1; i < n; ++i) {
      if (properties[i][1] < max_defense) {
        ++answer;
      } else {
        max_defense = properties[i][1];
      }
    }

    return answer;
  }
};
