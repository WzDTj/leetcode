#include <string>

using namespace std;

class Solution {
public:
  int maxPower(string s) {
    int n = s.length();

    int answer = 0, count = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] == s[i]) {
        ++count;
      } else {
        answer = max(answer, count);
        count = 1;
      }
    }

    return max(answer, count);
  }
};
