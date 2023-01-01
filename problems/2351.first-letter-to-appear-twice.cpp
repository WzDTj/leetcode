#include <string>

using namespace std;

class Solution {
public:
  char repeatedCharacter(string s) {
    int tmp = 0;
    for (char ch : s) {
      int n = 1 << (ch - 'a');

      if (tmp & n) {
        return ch;
      }

      tmp |= n;
    }

    return ' ';
  }
};
