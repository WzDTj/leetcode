#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    int n = names.size();
    vector<int> results(n);
    iota(results.begin(), results.end(), 0);
    sort(results.begin(), results.end(),
         [&](int x, int y) { return heights[x] > heights[y]; });

    vector<string> answer(n);
    for (int i = 0; i < n; ++i) {
      answer[i] = names[results[i]];
    }

    return answer;
  }
};