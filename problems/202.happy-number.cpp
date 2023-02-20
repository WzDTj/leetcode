#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_map<long, bool> map;
    long num = n;

    while (num != 1 && !map.count(num)) {
      long sum = 0;
      map[num] = true;

      while (num) {
        int r = num % 10;
        sum += r * r;
        num /= 10;
      }

      num = sum;
    }

    return num == 1;
  }
};
