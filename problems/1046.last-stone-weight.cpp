#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> q;

    for (auto stone : stones) {
      q.push(stone);
    }

    while (2 <= q.size()) {
      int y = q.top();
      q.pop();
      int x = q.top();
      q.pop();

      if (x != y) {
        q.push(y - x);
      }
    }

    return q.empty() ? 0 : q.top();
  }
};
