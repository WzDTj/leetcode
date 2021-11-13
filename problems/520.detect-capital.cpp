#include <string>

using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    int uppercase_count = 0, lowercase_count = 0;
    for (char ch : word) {
      if ('a' <= ch && ch <= 'z')
        ++lowercase_count;
      else if ('A' <= ch && ch <= 'Z')
        ++uppercase_count;
    }

    return !uppercase_count || !lowercase_count ||
           (uppercase_count == 1 && 'A' <= word[0] && word[0] <= 'Z');
  }
};
