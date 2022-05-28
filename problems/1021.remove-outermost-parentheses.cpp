#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {
    string answer = "";

    stack<char> stk;
    for (char ch : s) {
      if (ch == ')')
        stk.pop();
      if (!stk.empty())
        answer.push_back(ch);
      if (ch == '(')
        stk.push(ch);
    }

    return answer;
  }
};
