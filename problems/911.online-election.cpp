#include <unordered_map>
#include <vector>

using namespace std;

class TopVotedCandidate {
  vector<pair<int, int>> votes;

public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    int n = times.size();
    if (!n)
      return;

    unordered_map<int, int> map;

    int top_voted_candidate = 0;
    int max_votes = 0;
    for (int i = 0; i < n; ++i) {
      ++map[persons[i]];
      if (max_votes <= map[persons[i]]) {
        max_votes = map[persons[i]];
        top_voted_candidate = persons[i];
      }

      votes.push_back({times[i], top_voted_candidate});
    }
  }

  int q(int t) {
    int n = votes.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      votes[m].first < t ? l = m + 1 : r = m;
    }

    return l == n || votes[l].first != t ? votes[l - 1].second
                                         : votes[l].second;
  }
};
