#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();

    vector<int> answer(n);

    int l = 0, r = n - 1;
    int i = n - 1;
    while (l <= r) {
      int l_square = nums[l] * nums[l];
      int r_square = nums[r] * nums[r];

      if (l_square < r_square) {
        answer[i--] = r_square;
        --r;
      } else {
        answer[i--] = l_square;
        ++l;
      }
    }

    return answer;
  }
};
