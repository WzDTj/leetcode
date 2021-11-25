#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    string tmp;
    for (char &ch : s) {
      if (48 <= ch && ch <= 57)
        tmp.push_back(ch);
      else if (65 <= ch && ch <= 90)
        tmp.push_back(ch + 32);
      else if (97 <= ch && ch <= 122)
        tmp.push_back(ch);
    }

    int n = tmp.size();
    for (int i = 0; i < n >> 1; ++i) {
      if (tmp[i] != tmp[n - i - 1])
        return false;
    }
    return true;
  }
};
