#include <string>

using namespace std;

class Solution {
public:
  string defangIPaddr(string address) {
    string answer = "";

    for (auto ch : address) {
      answer.append(ch == '.' ? "[.]" : string(1, ch));
    }

    return answer;
  }
};
