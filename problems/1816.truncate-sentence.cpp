#include <string>

using namespace std;

class Solution {
public:
  string truncateSentence(string s, int k) {
    int n = s.length();

    int i = 0;
    while (i < n && 0 < k) {
      if (s[i++] == ' ')
        --k;
    }

    if (i != n)
      --i;

    return s.substr(0, i);
  }
};
