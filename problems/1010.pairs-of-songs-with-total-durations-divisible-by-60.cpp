#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

// 哈希优化

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    vector<int> memo(60, 0);

    int answer = 0;
    for (int num : time) {
      int tmp = (60 - num % 60) % 60;
      answer += memo[tmp];
      ++memo[num % 60];
    }

    return answer;
  }
};

// 哈希

// class Solution {
// public:
//   int numPairsDivisibleBy60(vector<int> &time) {
//     int n = time.size();
//
//     unordered_map<int, int> map;
//     for (int x : time) {
//       ++map[x];
//     }
//
//     int answer = 0;
//
//     for (auto it_x = map.begin(); it_x != map.end(); it_x++) {
//       for (auto it_y = it_x; it_y != map.end(); it_y++) {
//         if ((it_x->first + it_y->first) % 60 == 0) {
//           if (it_x == it_y && 2 <= it_x->second) {
//             answer +=
//                 tgamma(it_x->second + 1) / tgamma(it_x->second - 2 + 1) / 2;
//           } else if (it_x != it_y) {
//             answer += it_x->second * it_y->second;
//           }
//         }
//       }
//     }
//
//     return answer;
//   }
// };
