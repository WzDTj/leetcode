#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    int m = pattern.length();
    int n = s.length();

    unordered_map<char, string> ps_map;
    unordered_map<string, char> sp_map;

    int l = 0, r = 0;
    for (char ch : pattern) {
      if (n <= l) {
        return false;
      }
      while (r < n && s[r] != ' ') {
        ++r;
      }

      string substr = s.substr(l, r - l);
      ++r;
      l = r;

      if (ps_map.count(ch) && ps_map[ch] != substr) {
        return false;
      }
      if (sp_map.count(substr) && sp_map[substr] != ch) {
        return false;
      }

      ps_map[ch] = substr;
      sp_map[substr] = ch;
    }

    return n < l;
  }
};
