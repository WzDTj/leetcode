#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> answer(rowIndex + 1);

    for (int i = 0; i < rowIndex + 1; i++) {
      for (int j = i; 0 <= j; j--) {
        j == 0 || j == i ? answer[j] = 1 : answer[j] += answer[j - 1];
      }
    }

    return answer;
  }
};
