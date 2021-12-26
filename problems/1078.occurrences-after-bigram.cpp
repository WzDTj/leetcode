#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    int n = text.length();

    vector<string> words;

    int l = 0, r = 0;
    for (int r = 0; r <= n; ++r) {
      if (r == n || text[r] == ' ') {
        string substr = text.substr(l, r - l);
        words.push_back(substr);
        l = r + 1;
      }
    }

    vector<string> answer;
    for (int i = 2; i < words.size(); ++i) {
      if (words[i - 2] == first && words[i - 1] == second)
        answer.push_back(words[i]);
    }

    return answer;
  }
};
