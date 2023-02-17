#include <vector>

using namespace std;

class Solution {
public:
  double average(vector<int> &salary) {
    int sum = 0, minimum = 1e9, maximum = -1;
    int n = salary.size();

    for (auto num : salary) {
      sum += num;

      if (num < minimum) {
        minimum = num;
      }
      if (maximum < num) {
        maximum = num;
      }
    }

    return (sum - minimum - maximum) / double(n - 2);
  }
};
