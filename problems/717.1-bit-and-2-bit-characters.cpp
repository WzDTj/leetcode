#include <vector>

using namespace std;

class Solution {
public:
  // 逆序遍历

  bool isOneBitCharacter(vector<int> &bits) {
    int n = bits.size();

    int i = n - 2, count = 0;
    while (0 <= i && bits[i]) {
      ++count;
      --i;
    }

    return (count + 1) % 2;
  }

  // 正序遍历

  // bool isOneBitCharacter(vector<int> &bits) {
  //   int n = bits.size();
  //
  //   int i = 0;
  //   while (i < n - 1) {
  //     i += bits[i] == 0 ? 1 : 2;
  //   }
  //
  //   return i == n - 1;
  // }
};
