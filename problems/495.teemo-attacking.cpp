#include <vector>

using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {

    int answer = 0;

    int previous_end_time = -1;
    for (int start_time : timeSeries) {
      int end_time = start_time + duration - 1;

      answer += previous_end_time < start_time ? duration
                                               : end_time - previous_end_time;

      previous_end_time = end_time;
    }

    return answer;
  }
};
