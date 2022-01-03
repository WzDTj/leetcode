#include <string>
#include <vector>

using namespace std;

// 蔡勒公式

class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    vector<string> values = {
        "Sunday",   "Monday", "Tuesday",  "Wednesday",
        "Thursday", "Friday", "Saturday",
    };

    int y, c, m;
    if (month <= 2) {
      m = month + 12;
      y = (year - 1) % 100;
      c = (year - 1) / 100;
    } else {
      m = month;
      y = year % 100;
      c = year / 100;
    }

    int w =
        (y + (y / 4) + (c / 4) - 2 * c + ((26 * (m + 1)) / 10) + day - 1) % 7;

    return values[(w % 7 + 7) % 7];
  }
};
