#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();

    int answer = 0;

    int min_price = prices[0];
    for (int i = 0; i < n; ++i) {
      min_price = min(min_price, prices[i]);
      answer = max(answer, prices[i] - min_price);
    }

    return answer;
  }
};
