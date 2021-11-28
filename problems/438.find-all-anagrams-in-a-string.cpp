#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  // 滑动窗口

  vector<int> findAnagrams(string s, string p) {
    int s_length = s.length();
    int p_length = p.length();

    if (s_length < p_length)
      return vector<int>();

    vector<int> memo(26, 0);

    for (int i = 0; i < p_length; ++i) {
      ++memo[s[i] - 'a'];
      --memo[p[i] - 'a'];
    }

    int diff = 0;
    for (int x : memo) {
      diff += x == 0 ? 0 : 1;
    }

    vector<int> answer;
    if (!diff)
      answer.push_back(0);

    for (int i = 0; i < s_length - p_length; ++i) {
      if (--memo[s[i] - 'a'] == 0)
        --diff;
      else if (memo[s[i] - 'a'] == -1)
        ++diff;

      if (++memo[s[i + p_length] - 'a'] == 0)
        --diff;
      else if (memo[s[i + p_length] - 'a'] == 1)
        ++diff;

      if (!diff)
        answer.push_back(i + 1);
    }

    return answer;
  }

  // 模拟

  // vector<int> findAnagrams(string s, string p) {
  //   unordered_map<char, int> map;
  //
  //   for (char &ch : p)
  //     ++map[ch];
  //
  //   int n = s.length();
  //   int p_length = p.length();
  //
  //   vector<int> answer;
  //   int l = 0;
  //   int r = 0;
  //   while (l < n) {
  //     if (map.count(s[r])) {
  //       if (map[s[r]]) {
  //         --map[s[r]];
  //         if (r - l + 1 == p_length) {
  //           answer.push_back(l);
  //           ++map[s[l]];
  //           l++;
  //         }
  //         r++;
  //       } else {
  //         ++map[s[l]];
  //         l++;
  //       }
  //     } else {
  //       if (l != r)
  //         while (l < r)
  //           ++map[s[l++]];
  //
  //       ++r;
  //       ++l;
  //     }
  //   }
  //
  //   return answer;
  // }
};
