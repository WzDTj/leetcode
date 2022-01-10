#include <string>

using namespace std;

class Solution {
public:
  bool isAdditiveNumber(string num) {
    int n = num.length();

    for (int i = 1; i < n; ++i) {
      string lhs = num.substr(0, i);
      for (int j = 1; j < n; ++j) {
        if (1 < j && num[i] == '0' || n <= i + j) {
          break;
        }
        string rhs = num.substr(i, j);

        bool result = check(num, lhs, rhs);

        if (result) {
          return true;
        }
      }
    }

    return false;
  }

private:
  bool check(string &num, string lhs, string rhs) {
    int n = num.length();

    string first = lhs;
    string second = rhs;

    int position = first.length() + second.length();

    while (position < n) {
      string result = add(first, second);
      string tmp = num.substr(position, result.length());

      if (result != tmp) {
        return false;
      }

      first = second;
      second = result;
      position += result.length();
    }

    return true;
  }

  string add(string lhs, string rhs) {
    if (lhs == "0")
      return rhs;

    if (rhs == "0")
      return lhs;

    int length_lhs = lhs.length() - 1;
    int length_rhs = rhs.length() - 1;

    string answer = "";

    int carry = 0;
    while (0 <= length_lhs || 0 <= length_rhs || carry) {
      int lhs_num = 0 <= length_lhs ? lhs[length_lhs--] - '0' : 0;
      int rhs_num = 0 <= length_rhs ? rhs[length_rhs--] - '0' : 0;

      int result = lhs_num + rhs_num + carry;
      carry = result / 10;
      int remainder = result % 10;

      answer.push_back(remainder + '0');
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
