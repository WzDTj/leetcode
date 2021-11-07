#include <string>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    int length_num1 = num1.length();
    int length_num2 = num2.length();

    string answer = "0";

    for (int i = 0; i < length_num2; ++i) {
      string tmp = multiply(num1, num2[length_num2 - i - 1]);

      for (int j = 0; j < i; ++j)
        tmp.push_back('0');

      answer = add(answer, tmp);
    }

    return answer;
  }

private:
  string multiply(string num, char ch) {
    if (ch == '0')
      return "0";

    int n = num.length() - 1;

    string answer = "";
    int carry = 0;

    while (0 <= n) {
      int lhs = num[n--] - '0';
      int rhs = ch - '0';

      int result = lhs * rhs + carry;
      carry = result / 10;
      int remainder = result % 10;

      answer.push_back(remainder + '0');
    }

    if (carry)
      answer.push_back(carry + '0');

    reverse(answer.begin(), answer.end());

    return answer;
  }

  string add(string num1, string num2) {
    if (num1 == "0")
      return num2;

    if (num2 == "0")
      return num1;

    int length_num1 = num1.length() - 1;
    int length_num2 = num2.length() - 1;

    string answer = "";

    int carry = 0;
    while (0 <= length_num1 || 0 <= length_num2 || carry) {
      int lhs = 0 <= length_num1 ? num1[length_num1--] - '0' : 0;
      int rhs = 0 <= length_num2 ? num2[length_num2--] - '0' : 0;

      int result = lhs + rhs + carry;
      carry = result / 10;
      int remainder = result % 10;

      answer.push_back(remainder + '0');
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
