#include <string>

using namespace std;

class Solution {
public:
  bool digitCount(string num) {
    int n = num.length();

    int counts[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (char ch : num) {
      counts[ch - '0']++;
    }

    for (int i = 0; i < n; ++i) {
      if (counts[i] != num[i] - '0') {
        return false;
      }
    }

    return true;
  }
};
