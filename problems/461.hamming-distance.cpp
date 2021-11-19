class Solution {
public:
  int hammingDistance(int x, int y) {
    int answer = 0;

    int tmp = x ^ y;

    while (tmp) {
      answer += tmp & 1;

      tmp >>= 1;
    }

    return answer;
  }
};
