#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int dayOfYear(string date) {
    int year = stringToInteger(date.substr(0, 4));
    int month = stringToInteger(date.substr(5, 2));
    int day = stringToInteger(date.substr(8, 2));

    int answer = 0;
    vector<int> memo{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < month - 1; ++i) {
      answer += memo[i];
    }

    if (2 < month && isLeapYear(year)) {
      ++answer;
    }

    answer += day;

    return answer;
  }

private:
  int stringToInteger(string s) {
    int num = 0;

    for (char ch : s) {
      num = num * 10 + (ch - '0');
    }

    return num;
  }
  bool isLeapYear(int year) {
    return (!(year % 4) && year % 100) || !(year % 400);
  }
};
