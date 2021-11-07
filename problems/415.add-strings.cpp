#include <string>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
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
