#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int a_count = a.length();
    int b_count = b.length();

    string answer = "";
    int carry = 0;
    while (a_count || b_count || carry) {
      int a_num = a_count ? a[--a_count] - '0' : 0;
      int b_num = b_count ? b[--b_count] - '0' : 0;

      int tmp = a_num + b_num + carry;

      carry = tmp / 2;
      answer.push_back(tmp % 2 + '0');
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
