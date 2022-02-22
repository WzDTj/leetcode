#include <string>

using namespace std;

class Solution {
public:
  int titleToNumber(string columnTitle) {
    int answer = 0;

    for (char ch : columnTitle) {
      answer = answer * 26 - 64 + ch;
    }

    return answer;
  }
};
