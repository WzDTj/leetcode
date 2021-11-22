#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // KMP

  int strStr(string haystack, string needle) {
    int haystack_length = haystack.length();
    int needle_length = needle.length();

    vector<int> next = generateNext(needle);

    int i = 0, j = 0;
    while (i < haystack_length && j < needle_length) {
      if (j == -1 || haystack[i] == needle[j]) {
        ++i, ++j;
      } else {
        j = next[j];
      }
    }

    return needle_length <= j ? i - j : -1;
  }

private:
  vector<int> generateNext(string str) {
    int n = str.length();

    vector<int> next(n, -1);

    int i = -1, j = 0;

    while (j < n - 1) {
      i == -1 || str[i] == str[j] ? next[++j] = ++i : i = next[i];
    }

    return next;
  }

  // 暴力

  // int strStr(string haystack, string needle) {
  //   int haystack_length = haystack.length();
  //   int needle_length = needle.length();
  //
  //   if (!needle_length)
  //     return 0;
  //
  //   for (int i = 0; i < haystack_length; i++) {
  //     if (haystack_length - i < needle_length)
  //       break;
  //
  //     bool match = true;
  //
  //     for (int j = 0; j < needle_length; j++) {
  //       if (haystack[i + j] != needle[j]) {
  //         match = false;
  //         break;
  //       }
  //     }
  //
  //     if (match)
  //       return i;
  //   }
  //
  //   return -1;
  // }
};
