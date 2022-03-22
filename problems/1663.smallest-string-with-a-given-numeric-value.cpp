#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string getSmallestString(int n, int k) {
    vector<char> sequence(n, 'a');

    int remainder = k - n;

    auto it = sequence.rbegin();
    while (remainder && it != sequence.rend()) {
      int tmp = remainder <= 25 ? remainder : 25;
      *(it++) += tmp;
      remainder -= tmp;
    }

    string answer = "";

    for (auto ch : sequence) {
      answer += ch;
    }

    return answer;
  }
};
