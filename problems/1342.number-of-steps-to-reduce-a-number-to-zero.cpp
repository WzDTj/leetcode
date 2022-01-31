class Solution {
public:
  int numberOfSteps(int num) {
    int answer = 0;

    while (0 < num) {
      num & 1 ? --num : num >>= 1;
      ++answer;
    }

    return answer;
  }
};
