#include <string>

using namespace std;

class Solution {
public:
  string toLowerCase(string s) {
    for (char &ch : s)
      if (65 <= ch && ch <= 90)
        ch += 32;

    return s;
  }
};
