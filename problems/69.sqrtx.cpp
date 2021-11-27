class Solution {
public:
  int mySqrt(int x) {
    int l = 1, r = x;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      m < x / m ? l = m + 1 : r = m;
    }

    return x / l == l ? l : l - 1;
  }
};
