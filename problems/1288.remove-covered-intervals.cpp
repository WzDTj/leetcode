#include <vector>

using namespace std;

bool compare(vector<int> lhs, vector<int> rhs) {
  return lhs[0] == rhs[0] ? rhs[1] < lhs[1] : lhs[0] < rhs[0];
}

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), compare);

    int n = intervals.size();

    int count = 0, max_end = intervals[0][1];

    for (int i = 1; i < n; ++i) {
      intervals[i][1] <= max_end ? ++count : max_end = intervals[i][1];
    }

    return n - count;
  }
};
