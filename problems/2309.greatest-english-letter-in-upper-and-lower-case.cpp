#include <string>
// #include <unordered_map>

using namespace std;

// 哈希

// class Solution {
// private:
//   string t = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
//
// public:
//   string greatestLetter(string s) {
//
//     unordered_map<char, bool> map;
//
//     for (auto ch : s) {
//       map[ch] = true;
//     }
//
//     for (auto ch : t) {
//       if (map[ch] && map[ch + 32]) {
//         return string(1, ch);
//       }
//     }
//
//     return "";
//   }
// };

// 位运算

class Solution {
public:
  string greatestLetter(string s) {

    int lower = 0, upper = 0;

    for (auto ch : s) {
      islower(ch) ? lower |= 1 << (ch - 'a') : upper |= 1 << (ch - 'A');
    }

    for (int i = 25; 0 <= i; --i) {
      if (lower & upper & (1 << i)) {
        return string(1, i + 'A');
      }
    }

    return "";
  }
};
