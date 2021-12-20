#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(heaters.begin(), heaters.end());

    int answer = 0;
    for (int house : houses) {
      int min_distance = 1e9;

      auto greater = upper_bound(heaters.begin(), heaters.end(), house);
      if (greater != heaters.end()) {
        min_distance = min(min_distance, *greater - house);
      }
      if (greater != heaters.begin()) {
        min_distance = min(min_distance, house - *(--greater));
      }

      answer = max(answer, min_distance);
    }

    return answer;
  }
};
