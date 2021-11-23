#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool buddyStrings(string s, string goal) {
    int s_length = s.length();
    int goal_length = goal.length();
    if (s_length != goal_length)
      return false;

    unordered_map<char, int> map;
    vector<int> mismatch_idx;

    int max_match_count = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] != goal[i]) {
        mismatch_idx.push_back(i);
      } else {
        map[s[i]]++;
        max_match_count = max(max_match_count, map[s[i]]);
      }
    }

    int mismatch_size = mismatch_idx.size();

    if (mismatch_size == 0 && 2 <= max_match_count)
      return true;
    if (mismatch_size == 2 && s[mismatch_idx[0]] == goal[mismatch_idx[1]] &&
        s[mismatch_idx[1]] == goal[mismatch_idx[0]])
      return true;

    return false;
  }
};
