#include <algorithm>

using namespace std;

class Solution {
public:
  int commonFactors(int a, int b) {
    int answer = 0;
    int c = gcd(a, b);

    for (int i = 1; i * i <= c; ++i) {
      if (c % i == 0) {
        answer++;
        if (i * i != c) {
          answer++;
        }
      }
    }

    return answer;
  }
};