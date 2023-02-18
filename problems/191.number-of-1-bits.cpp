#include <stdint.h>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int answer = 0;

    // 方案一: 不断判断奇偶并右移一位
    // while (n) {
    //   answer += (n & 1);
    //   n >>= 1;
    // }

    // 方案二: 不断将最低位置为 0, 直到 n 为 0
    while (n) {
      n &= n - 1;
      answer++;
    }

    return answer;
  }
};
