#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string getHint(string secret, string guess) {
    int n = secret.length();

    unordered_map<char, int> secret_map;
    unordered_map<char, int> guess_map;

    int bulls = 0, cows = 0;
    for (int i = 0; i < n; ++i) {
      if (secret[i] == guess[i]) {
        ++bulls;
      } else {
        ++secret_map[secret[i]];
        ++guess_map[guess[i]];
      }
    }

    for (auto [ch, count] : secret_map) {
      cows += min(count, guess_map[ch]);
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
