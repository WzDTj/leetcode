#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &score) {
    int n = score.size();

    vector<string> answer(n);

    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
      map[score[i]] = i;
    }

    sort(score.begin(), score.end(), greater<int>());
    for (int i = 0; i < n; ++i) {
      answer[map[score[i]]] = parseRank(i + 1);
    }

    return answer;
  }

private:
  string parseRank(int rank) {
    switch (rank) {
    case 1:
      return "Gold Medal";
    case 2:
      return "Silver Medal";
    case 3:
      return "Bronze Medal";
    default:
      return to_string(rank);
    }
  }
};
