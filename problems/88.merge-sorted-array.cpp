#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int index_nums1 = m - 1, index_nums2 = n - 1;
    for (int i = m + n - 1; 0 <= i; --i) {
      nums1[i] = index_nums1 < 0   ? nums2[index_nums2--]
                 : index_nums2 < 0 ? nums1[index_nums1--]
                 : nums1[index_nums1] < nums2[index_nums2]
                     ? nums2[index_nums2--]
                     : nums1[index_nums1--];
    }
  }
};
