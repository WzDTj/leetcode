#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int len = s.length();

    vector<int> vec(26, 0);

    for (int i = 0; i < len; ++i)
      vec[s[i] - 97]++;

    for (int i = 0; i < len; ++i)
      if (vec[s[i] - 97] == 1)
        return i;

    return -1;
  }
};
