#include <string>

using namespace std;

class Solution {
public:
  int countAsterisks(string s) {
    int answer = 0;
    bool valid = true;

    for (auto ch : s) {
      if (ch == '|') {
        valid = !valid;
      } else if (ch == '*' && valid) {
        answer++;
      }
    }

    return answer;
  }
};
