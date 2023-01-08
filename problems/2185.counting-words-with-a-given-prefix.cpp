#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int answer = 0;

    int n = pref.size();

    for (string word : words) {
      if (word.compare(0, n, pref) == 0) {
        answer++;
      }
    }

    return answer;
  }
};
