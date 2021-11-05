#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int answer = 1;

    unordered_map<int, int> hash_map;
    for (int v : arr) {
      hash_map[v] = hash_map[v - difference] + 1;

      answer = max(answer, hash_map[v]);
    }

    return answer;
  }
};
