#include <vector>

using namespace std;

class Solution {
public:
  int heightChecker(vector<int> &heights) {
    vector<int> vec(101, 0);

    int min_height = heights[0], max_height = heights[0];
    for (int height : heights) {
      ++vec[height];
      min_height = min(min_height, height);
      max_height = max(max_height, height);
    }

    int answer = 0, count = 0;
    for (int i = min_height; i < max_height + 1; ++i) {
      while (vec[i]--) {
        if (heights[count++] != i)
          ++answer;
      }
    }

    return answer;
  }
};
