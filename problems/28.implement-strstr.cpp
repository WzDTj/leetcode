#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int haystack_length = haystack.length();
    int needle_length = needle.length();

    if (!needle_length)
      return 0;

    for (int i = 0; i < haystack_length; i++) {
      if (haystack_length - i < needle_length)
        break;

      bool match = true;

      for (int j = 0; j < needle_length; j++) {
        if (haystack[i + j] != needle[j]) {
          match = false;
          break;
        }
      }

      if (match)
        return i;
    }

    return -1;
  }
};
