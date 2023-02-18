#include <vector>

using namespace std;

class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    int minimum_distance = 1e9, minimum_index = -1;
    int n = points.size();

    for (int i = 0; i < n; ++i) {
      if (points[i][0] != x && points[i][1] != y) {
        continue;
      }

      int distance = abs(x - points[i][0]) + abs(y - points[i][1]);

      if (distance < minimum_distance) {
        minimum_distance = distance;
        minimum_index = i;
      }
    }

    return minimum_index;
  }
};
