#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    int carry = 1;

    vector<int> answer;
    for (int i = n - 1; 0 <= i; --i) {
      int tmp = digits[i] + carry;
      carry = tmp / 10;
      answer.push_back(tmp % 10);
    }
    if (carry) {
      answer.push_back(carry);
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};
