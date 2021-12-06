#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map;

    for (int num : nums1) {
      map[num] = 1;
    }

    vector<int> answer;
    for (int num : nums2) {
      if (!map[num])
        continue;

      map[num] = 0;
      answer.push_back(num);
    }

    return answer;
  }
};
