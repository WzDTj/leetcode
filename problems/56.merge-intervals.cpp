#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (vector<int> &interval : intervals) {
      int start = interval[0], end = interval[1];

      if (!result.size() || result.back()[1] < start) {
        result.push_back({start, end});
      } else {
        result.back()[1] = max(end, result.back()[1]);
      }
    }

    return result;
  }
};
