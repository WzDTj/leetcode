#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    int n = s.length();

    if (n % 2)
      return false;

    unordered_map<char, char> map{
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };

    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        stack.push(s[i]);
      else if (stack.empty())
        return false;
      else if (map[stack.top()] == s[i])
        stack.pop();
      else
        return false;
    }

    return stack.empty();
  }
};
