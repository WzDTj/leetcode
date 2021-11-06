#include <vector>

using namespace std;

class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    int n = arr.size();

    int max_num = -1;

    for (int i = n - 1; 0 <= i; --i) {
      int tmp = arr[i];
      arr[i] = max_num;
      max_num = max(max_num, tmp);
    }

    return arr;
  }
};
