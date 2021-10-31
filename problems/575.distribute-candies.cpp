#include <vector>

using namespace std;

class Solution {
public:
  int distributeCandies(vector<int> &candyType) {
    int n = candyType.size();
    sort(candyType.begin(), candyType.end());

    int count = 1;
    for (int i = 1; i < n; ++i) {
      if (candyType[i - 1] != candyType[i])
        ++count;
    }

    return min(count, n / 2);
  }
};
