#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int n = s.length();

    string answer = "";

    for (int l = 0, r = 0; r <= n; r++) {
      if (s[r] == ' ' || s[l] == ' ' || r == n) {
        for (int j = r - 1; l <= j; j--)
          answer.push_back(s[j]);

        l = r;
      }
    }

    return answer;
  }
};
