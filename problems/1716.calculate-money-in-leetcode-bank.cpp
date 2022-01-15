class Solution {
public:
  int totalMoney(int n) {
    int weeks = n / 7;
    int left = n % 7;

    int first_week = (1 + 7) * 7 / 2;
    int last_week = (weeks * 2 + 6) * 7 / 2;
    int other = (weeks * 2 + left + 1) * left / 2;

    int answer = (first_week + last_week) * weeks / 2 + other;

    return answer;
  }
};
