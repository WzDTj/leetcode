#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string decodeMessage(string key, string message) {
    unordered_map<char, char> map;
    string answer = "";

    char letter = 'a';
    for (char ch : key) {
      if (ch == ' ' || map.count(ch)) {
        continue;
      }
      map[ch] = letter++;
    }

    for (char ch : message) {
      char tmp = ch == ' ' ? ch : map[ch];
      answer.push_back(tmp);
    }

    return answer;
  }
};
