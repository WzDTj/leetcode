#include <string>

using namespace std;

// 模拟

class Solution {
public:
  bool rotateString(string s, string goal) {
    int s_length = s.length();
    int g_length = goal.length();

    if (s_length != g_length) {
      return false;
    }

    for (int i = 0; i < g_length; ++i) {
      if (goal[i] != s[0]) {
        continue;
      }

      int j = 0;
      while (j < s_length && s[j] == goal[(i + j) % s_length]) {
        j++;
      }

      if (j == s_length) {
        return true;
      }
    }

    return false;
  }
};
