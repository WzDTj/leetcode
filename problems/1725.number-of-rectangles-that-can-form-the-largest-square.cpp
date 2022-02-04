#include <vector>

using namespace std;

class Solution {
public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int answer = 0, max_len = 0;

    for (auto rectangle : rectangles) {
      int len = rectangle[0] < rectangle[1] ? rectangle[0] : rectangle[1];

      if (max_len < len) {
        max_len = len;
        answer = 1;
      } else if (max_len == len) {
        ++answer;
      }
    }

    return answer;
  }
};
