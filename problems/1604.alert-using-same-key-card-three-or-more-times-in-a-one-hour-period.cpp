#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  bool check(vector<int> vec) {
    int n = vec.size();
    for (int i = 2; i < n; ++i) {
      if (vec[i] - vec[i - 2] <= 60) {
        return true;
      }
    }

    return false;
  }

public:
  vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
    vector<string> answer = {};
    unordered_map<string, vector<int>> map;

    int n = keyName.size();

    for (int i = 0; i < n; ++i) {
      string time = keyTime[i];
      int minutes = (time[0] - '0') * 600 + (time[1] - '0') * 60 +
                    (time[3] - '0') * 10 + (time[4] - '0');
      map[keyName[i]].emplace_back(minutes);
    }

    for (auto &[name, times] : map) {
      sort(times.begin(), times.end());
      if (check(times)) {
        answer.emplace_back(name);
      }
    }

    sort(answer.begin(), answer.end());

    return answer;
  }
};
