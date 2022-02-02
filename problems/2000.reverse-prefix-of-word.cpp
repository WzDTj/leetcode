#include <string>

using namespace std;

class Solution {
public:
  string reversePrefix(string word, char ch) {
    int n = word.length();

    int r = 0;
    while (r < n && word[r] != ch) {
      ++r;
    }

    if (r == n) {
      return word;
    }

    for (int i = 0; i <= (r >> 1); ++i) {
      swap(word[i], word[r - i]);
    }

    return word;
  }
};
