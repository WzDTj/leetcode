#include <vector>

using namespace std;

// 迭代

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> answer(n);

    int current = 1;
    for (int i = 0; i < n; ++i) {
      answer[i] = current;

      if (current * 10 <= n) {
        current *= 10;
      } else {
        while (current % 10 == 9 || n < current + 1) {
          current /= 10;
        }
        ++current;
      }
    }

    return answer;
  }
};

// 递归

// class Solution {
// public:
//   vector<int> lexicalOrder(int n) {
//     vector<int> answer;
//
//     for (int i = 1; i < 10; ++i) {
//       dfs(i, n, answer);
//     }
//
//     return answer;
//   }
//
// private:
//   void dfs(int current, int n, vector<int> &vec) {
//     if (n < current)
//       return;
//
//     vec.push_back(current);
//
//     for (int i = 0; i < 10; ++i) {
//       dfs(current * 10 + i, n, vec);
//     }
//   }
// };
