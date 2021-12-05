#include <vector>

using namespace std;

class Solution {
public:
  // 二分查找
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int n = arr.size();

    int l = 0, r = n - k;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      arr[m + k] - x < x - arr[m] ? l = m + 1 : r = m;
    }

    vector<int> answer;
    for (int i = l; i < l + k; ++i) {
      answer.push_back(arr[i]);
    }

    return answer;
  }

  // 二分查找 + 双指针

  // vector<int> findClosestElements(vector<int> &arr, int k, int x) {
  //   int n = arr.size();
  //
  //   int l = 0, r = n;
  //   while (l < r) {
  //     int m = l + ((r - l) >> 1);
  //     arr[m] < x ? l = m + 1 : r = m;
  //   }
  //
  //   while (r - l < k) {
  //     if (l == 0) {
  //       ++r;
  //     } else if (n == r) {
  //       --l;
  //     } else if (x - arr[l - 1] <= arr[r] - x) {
  //       --l;
  //     } else {
  //       ++r;
  //     }
  //   }
  //
  //   vector<int> answer;
  //   for (int i = l; i < r; ++i) {
  //     answer.push_back(arr[i]);
  //   }
  //
  //   return answer;
  // }
};
