class Solution {
public:
  bool checkPerfectNumber(int num) {
    int answer = 0;

    for (int i = 1; i * i <= num; ++i) {
      if (num % i == 0) {
        answer += i == num / i ? i : num / i + i;
      }
    }

    return answer == 2 * num;
  }
};
