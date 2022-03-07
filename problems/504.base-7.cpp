#include <string>

using namespace std;

class Solution {
public:
  string convertToBase7(int num) {
    if (!num) {
      return "0";
    }

    bool is_positive = 0 <= num;

    if (!is_positive) {
      num = -num;
    }

    string answer = "";
    while (num) {
      answer.push_back(num % 7 + '0');
      num /= 7;
    }

    if (!is_positive) {
      answer.push_back('-');
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
