#include <math.h>

using namespace std;

class Solution {
public:
  // 数学

  int arrangeCoins(int n) { return (sqrt((long)n * 8 + 1) - 1) / 2; }

  // 二分查找

  // int arrangeCoins(int n) {
  //   long l = 0, r = n;
  //
  //   while (l < r) {
  //     long m = l + ((r - l) >> 1);
  //     long tmp = ((m + 1) * m) >> 1;
  //     tmp < n ? l = m + 1 : r = m;
  //   }
  //
  //   return ((l + 1) * l) >> 1 == n ? l : l - 1;
  // }

  // 暴力迭代

  // int arrangeCoins(int n) {
  //   int answer = 0, result = n;
  //
  //   for (int i = 1; 0 <= result; ++i) {
  //     result -= i;
  //     ++answer;
  //   }
  //
  //   return answer - 1;
  // }
};
