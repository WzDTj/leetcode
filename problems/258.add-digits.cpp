// 循环

// class Solution {
// public:
//   int addDigits(int num) {
//     int answer = num;
//     while (10 <= answer) {
//       int next_num = 0;
//       while (answer != 0) {
//         next_num += answer % 10;
//         answer /= 10;
//       }
//       answer = next_num;
//     }
//     return answer;
//   }
// };

// 数论

class Solution {
public:
  int addDigits(int num) { return (num - 1) % 9 + 1; }
};
