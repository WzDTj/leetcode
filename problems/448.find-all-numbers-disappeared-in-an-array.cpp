#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n;) {
      if (nums[i] == i + 1 || nums[i] == nums[nums[i] - 1])
        i++;
      else
        swap(nums[i], nums[nums[i] - 1]);
    }

    vector<int> answer;

    for (int i = 0; i < n; ++i)
      if (nums[i] != i + 1)
        answer.push_back(i + 1);

    return answer;
  }
};
