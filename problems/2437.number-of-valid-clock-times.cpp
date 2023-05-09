#include <string>

using namespace std;

class Solution {
public:
  int countTime(string time) {
    int answer = 1;

    answer *= time[3] == '?' ? 6 : 1;
    answer *= time[4] == '?' ? 10 : 1;

    if (time[0] == '?' && time[1] == '?') {
      return answer * 24;
    }

    answer *= time[0] != '?' ? 1 : time[1] < '4' ? 3 : 2;
    answer *= time[1] != '?' ? 1 : time[0] == '2' ? 4 : 10;

    return answer;
  }
};
