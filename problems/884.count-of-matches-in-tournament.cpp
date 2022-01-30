#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> map;

    countWords(s1, map);
    countWords(s2, map);

    vector<string> answer;
    for (auto [word, count] : map) {
      if (count == 1) {
        answer.push_back(word);
      }
    }

    return answer;
  }

private:
  void countWords(string s, unordered_map<string, int> &map) {
    int n = s.length();

    int l = 0, r = 0;
    while (r <= n) {
      if (r == n || s[r] == ' ') {
        string substr = s.substr(l, r - l);
        ++map[substr];
        l = r + 1;
      }
      ++r;
    }
  }
};
