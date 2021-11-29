// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 0, r = n;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      isBadVersion(m) ? r = m : l = m + 1;
    }

    return l;
  }
};
