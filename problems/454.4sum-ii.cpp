#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> map;

    for (int i : nums1) {
      for (int j : nums2) {
        ++map[i + j];
      }
    }

    int answer = 0;

    for (int k : nums3) {
      for (int l : nums4) {
        answer += map[-k - l];
      }
    }

    return answer;
  }
};
