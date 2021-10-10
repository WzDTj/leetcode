#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string answer = s.substr(0, 1);

    int length = s.length();

    for (int i = 0; i < length; i++) {
      for (int j = length - 1; i < j; j--) {
        if (s[i] != s[j])
          continue;

        int l = i, r = j;

        while (l < r) {
          if (s[l] != s[r])
            break;
          l++, r--;
        }

        if (l >= r && answer.length() < j - i + 1) {
          answer = s.substr(i, j - i + 1);
        }
      }
    }

    return answer;
  }
};
