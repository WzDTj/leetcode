#include <algorithm>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string answer = "";

    int n = strs.size();

    int min_length = INT_MAX;
    for (string &str : strs) {
      int length = str.length();
      min_length = min(min_length, length);
    }

    for (int i = 0; i < min_length; ++i) {
      for (int j = 1; j < n; ++j) {
        if (strs[j][i] != strs[j - 1][i])
          return answer;
      }

      answer.push_back(strs[0][i]);
    }

    return answer;
  }
};
