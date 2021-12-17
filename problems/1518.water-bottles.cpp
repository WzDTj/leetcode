class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int answer = numBottles;

    int full_bottles = numBottles;
    int empty_bottles = 0;

    while (full_bottles) {
      empty_bottles += full_bottles;
      full_bottles = empty_bottles / numExchange;
      empty_bottles %= numExchange;

      answer += full_bottles;
    }

    return answer;
  }
};
