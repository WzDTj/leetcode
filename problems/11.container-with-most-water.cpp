#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int answer = 0;

    int l = 0, r = height.size() - 1;
    while (l < r) {
      answer = max(answer, min(height[l], height[r]) * (r - l));

      height[l] < height[r] ? ++l : --r;
    }

    return answer;
  }
};
