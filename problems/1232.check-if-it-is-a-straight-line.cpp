#include <vector>

using namespace std;

class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    int n = coordinates.size();

    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];

    for (int i = 2; i < n; ++i) {
      int x = coordinates[i][0];
      int y = coordinates[i][1];
      if ((y - y1) * (x2 - x1) != (x - x1) * (y2 - y1)) {
        return false;
      }
    }

    return true;
  }
};
