#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 位运算

  int maxProduct(vector<string> &words) {
    int n = words.size();
    int answer = 0;

    vector<int> bits(n, 0);

    for (int i = 0; i < n; ++i) {
      for (char ch : words[i]) {
        bits[i] |= 1 << (ch - 'a');
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (bits[i] & bits[j])
          continue;

        int tmp = words[i].length() * words[j].length();
        answer = max(answer, tmp);
      }
    }

    return answer;
  }

  // 暴力

  // int maxProduct(vector<string> &words) {
  //   int n = words.size();
  //   int answer = 0;
  //
  //   for (int i = 0; i < n; ++i) {
  //     vector<int> vec(26, 0);
  //
  //     for (char ch : words[i])
  //       vec[ch - 'a'] = 1;
  //
  //     for (int j = i + 1; j < n; ++j) {
  //       if (!valid(vec, words[j]))
  //         continue;
  //
  //       int tmp = words[i].length() * words[j].length();
  //       answer = max(answer, tmp);
  //     }
  //   }
  //
  //   return answer;
  // }

private:
  bool valid(vector<int> vec, string s) {

    for (char ch : s) {
      if (vec[ch - 'a'])
        return false;
    }

    return true;
  }
};
