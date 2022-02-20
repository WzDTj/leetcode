#include <vector>

using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    int n = bits.size();

    int i = 0;
    while (i < n - 1) {
      i += bits[i] == 0 ? 1 : 2;
    }

    return i == n - 1;
  }
};
