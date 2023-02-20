#include <string>

using namespace std;

class Solution {
public:
  // 统计计数

  bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    int count = 0;

    int diff[2] = {-1, -1};
    for (int i = 0; i < n; ++i) {
      if (s1[i] != s2[i]) {
        if (1 < count) {
          return false;
        }
        diff[count++] = i;
      }
    }

    if (!count) {
      return true;
    }

    return count == 2 && s1[diff[0]] == s2[diff[1]] &&
           s1[diff[1]] == s2[diff[0]];
  }

  // 模拟

  // bool areAlmostEqual(string s1, string s2) {
  //   int n = s1.length();
  //
  //   int i = 0;
  //   while (i < n && s1[i] == s2[i]) {
  //     i++;
  //   }
  //   if (i == n) {
  //     return true;
  //   }
  //
  //   int j = i + 1;
  //   while (j < n && (s1[i] != s2[j] || s1[j] != s2[i])) {
  //     j++;
  //   }
  //
  //   if (j == n) {
  //     return false;
  //   }
  //   swap(s2[i], s2[j]);
  //
  //   while (i < n && s1[i] == s2[i]) {
  //     i++;
  //   }
  //
  //   return i == n;
  // }
};
