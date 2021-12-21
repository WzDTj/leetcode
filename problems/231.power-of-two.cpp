#include <cmath>

using namespace std;

class Solution {
public:
  // 位运算
  bool isPowerOfTwo(int n) { return 0 < n && (n & -n) == n; }

  // 数学
  // bool isPowerOfTwo(int n) {
  //   if (n <= 0)
  //     return false;
  //   double result = log2(n);
  //   return result - (int)result == 0;
  // }
};
