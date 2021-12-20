#include <vector>

using namespace std;
class Solution {

public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> answer;

    int min_abs = INT_MAX;
    for (int i = 1; i < n; ++i) {
      if (arr[i] - arr[i - 1] < min_abs) {
        min_abs = arr[i] - arr[i - 1];
        answer.clear();
        answer.push_back({arr[i - 1], arr[i]});
      } else if (arr[i] - arr[i - 1] == min_abs) {
        answer.push_back({arr[i - 1], arr[i]});
      }
    }

    return answer;
  }
};
