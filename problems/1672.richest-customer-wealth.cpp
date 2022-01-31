#include <vector>

using namespace std;

class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int answer = 0;
    for (auto account : accounts) {
      int wealth = 0;
      for (auto bank : account) {
        wealth += bank;
      }

      if (answer < wealth) {
        answer = wealth;
      }
    }

    return answer;
  }
};
