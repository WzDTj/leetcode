#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
  unordered_map<int, int> memo;

public:
  int integerReplacement(int n) {
    if (n == 1)
      return 0;

    if (memo[n])
      return memo[n];

    memo[n] = n & 1 ? 2 + min(integerReplacement(n >> 1),
                              integerReplacement(1 + (n >> 1)))
                    : 1 + integerReplacement(n >> 1);

    return memo[n];
  }
};
