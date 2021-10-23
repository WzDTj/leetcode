#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int size_n1 = nums1.size();
    int size_n2 = nums2.size();
    int idx_n1 = 0, idx_n2 = 0;

    vector<int> answer;
    while (idx_n1 < size_n1 && idx_n2 < size_n2) {
      if (nums1[idx_n1] < nums2[idx_n2]) {
        ++idx_n1;
      } else if (nums2[idx_n2] < nums1[idx_n1]) {
        ++idx_n2;
      } else {
        answer.push_back(nums1[idx_n1]);
        ++idx_n1;
        ++idx_n2;
      }
    }

    return answer;
  }
};
