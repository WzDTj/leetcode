#include <string>

using namespace std;

class Solution {
public:
  string modifyString(string s) {
    int n = s.length();

    string answer = s;
    for (int i = 0; i < n; ++i) {
      if (answer[i] != '?')
        continue;

      char lhs = 0 <= i - 1 ? answer[i - 1] : '?';
      char rhs = i + 1 < n ? answer[i + 1] : '?';

      answer[i] = getChar(lhs, rhs);
    }

    return answer;
  }

private:
  char getChar(char lhs, char rhs) {
    if (lhs == '?' && rhs == '?') {
      return 'a';
    }

    char smaller = lhs < rhs ? lhs : rhs;
    char greater = lhs < rhs ? rhs : lhs;

    return smaller == '?' || smaller + 1 == greater
               ? (greater + 1 - 'a') % 26 + 'a'
               : (smaller + 1 - 'a') % 26 + 'a';
  }
};
