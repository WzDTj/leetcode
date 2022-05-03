#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string lhs, const string rhs) {
  int li = 0, ri = 0;
  while (lhs[li] != ' ')
    ++li;
  while (rhs[ri] != ' ')
    ++ri;

  string lhs_content = lhs.substr(li + 1);
  string rhs_content = rhs.substr(ri + 1);

  return lhs_content == rhs_content ? lhs < rhs : lhs_content < rhs_content;
}

class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    int n = logs.size();
    vector<string> num_logs, alpha_logs;

    for (auto log : logs) {
      int i = 0;
      while (log[i] != ' ')
        ++i;

      '0' <= log[i + 1] && log[i + 1] <= '9' ? num_logs.push_back(log)
                                             : alpha_logs.push_back(log);
    }

    sort(alpha_logs.begin(), alpha_logs.end(), compare);

    alpha_logs.insert(alpha_logs.end(), num_logs.begin(), num_logs.end());

    return alpha_logs;
  }
};
