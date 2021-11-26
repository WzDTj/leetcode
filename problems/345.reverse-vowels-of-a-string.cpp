#include <string>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    int n = s.length();

    string vowels = "aeiouAEIOU";

    int l = 0, r = n - 1;
    while (l < r) {
      if (vowels.find(s[l]) == -1)
        ++l;
      else if (vowels.find(s[r]) == -1)
        --r;
      else
        swap(s[l++], s[r--]);
    }

    return s;
  }
};
