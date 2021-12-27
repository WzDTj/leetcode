class Solution {
public:
  int bitwiseComplement(int n) {
    int height_bit = 0;
    for (int i = 30; 0 <= i; --i) {
      if ((1 << i) & n) {
        height_bit = i;
        break;
      }
    }

    return ((1LL << (height_bit + 1)) - 1) ^ n;
  }
};
