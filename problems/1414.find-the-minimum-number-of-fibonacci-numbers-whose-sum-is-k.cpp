#include <vector>

using namespace std;

class Solution {
public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fib_nums = {1, 1};

    int i = 2;
    while (fib_nums[i - 1] <= k) {
      int fib_num = fib_nums[i - 1] + fib_nums[i - 2];
      fib_nums.push_back(fib_num);
      ++i;
    }

    int answer = 0;
    while (k != 0) {
      if (fib_nums[i - 1] <= k) {
        k -= fib_nums[i - 1];
        ++answer;
      } else {
        --i;
      }
    }

    return answer;
  }
};
