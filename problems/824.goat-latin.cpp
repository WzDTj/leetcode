#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string toGoatLatin(string sentence) {

    int n = sentence.length();
    string vowels = "aeiouAEIOU";

    int word_count = 1;
    int l = 0, r = 0;
    string answer = "";
    while (r <= n) {
      if (sentence[r] == ' ' || r == n) {
        string sub;
        if (vowels.find(sentence[l]) != string::npos) {
          sub = sentence.substr(l, r - l);
        } else {
          sub = sentence.substr(l + 1, r - l - 1);
          sub += sentence[l];
        }
        sub += "ma" + string(word_count, 'a');

        answer += sub + (r == n ? "" : " ");

        l = r + 1;
        ++word_count;
      }

      ++r;
    }

    return answer;
  }
};
