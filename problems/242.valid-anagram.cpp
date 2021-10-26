#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int s_len = s.length();
    int t_len = t.length();

    if (s_len != t_len)
      return false;

    vector<int> vec(26, 0);

    for (int i = 0; i < s.length(); ++i)
      ++vec[s[i] - 97];

    for (int i = 0; i < t.length(); ++i)
      --vec[t[i] - 97];

    for (int i = 0; i < 26; ++i)
      if (vec[i])
        return false;

    return true;
  }
};
