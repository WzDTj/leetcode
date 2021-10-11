#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int l = 0, r = s.length() - 1;

    while (s[l] == ' ' || s[r] == ' ') {
      if (s[l] == ' ')
        l++;
      if (s[r] == ' ')
        r--;
    }

    string answer = "";

    for (int i = r++; l <= i; i--) {
      if ((i > l) && ((s[i] == ' ' && s[i - 1] == ' ') ||
                      (s[i] != ' ' && s[i - 1] != ' '))) {
        continue;
      }
      answer += s[i] != ' ' ? s.substr(i, r - i) : " ";

      r = i;
    }

    return answer;
  }
};
