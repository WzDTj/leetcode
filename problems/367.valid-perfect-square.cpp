class Solution {
public:
  bool isPerfectSquare(int num) {
    int l = 0, r = 46340;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      m *m < num ? l = m + 1 : r = m;
    }

    return l * l == num;
  }
};
