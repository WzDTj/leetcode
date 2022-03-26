#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int calPoints(vector<string> &ops) {
    int n = ops.size();

    vector<int> points(n, 0);
    int index = 0;
    for (auto op : ops) {
      switch (op[0]) {
      case '+':
        points[index++] = points[index - 1] + points[index - 2];
        break;
      case 'D':
        points[index++] = 2 * points[index - 1];
        break;
      case 'C':
        points[--index] = 0;
        break;
      default:
        int point = 0;
        bool is_negative = op[0] == '-';
        for (int i = is_negative; i < op.length(); ++i) {
          point *= 10;
          point += op[i] - '0';
        }
        points[index++] = is_negative ? -point : point;
        break;
      }
    }

    int answer = 0;

    for (auto point : points) {
      answer += point;
    }

    return answer;
  }
};
