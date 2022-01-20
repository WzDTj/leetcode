#include <vector>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    long long sum = 0;
    int max = 0;
    for (int pile : piles) {
      sum += pile;
      if (max < pile) {
        max = pile;
      }
    }

    int l = (sum - 1) / h + 1, r = max;

    while (l < r) {
      int m = l + ((r - l) >> 1);
      check(piles, h, m) ? r = m : l = m + 1;
    }

    return l;
  }

private:
  bool check(vector<int> &piles, int h, int x) {
    int sum = 0;

    for (int pile : piles) {
      sum += (pile - 1) / x + 1;
    }

    return sum <= h;
  }
};
