#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> map;

    for (auto ch : text) {
      ++map[ch];
    }

    return min({map['b'], map['a'], map['n'], map['l'] / 2, map['o'] / 2});
  }
};
