#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    int n = arr.size();

    unordered_map<int, int> map;

    for (int i = 0; i < n; ++i)
      map[arr[i]] = i;

    for (int i = 0; i < n; ++i) {
      unordered_map<int, int>::iterator it = map.find(arr[i] * 2);
      if (it != map.end() && it->second != i)
        return true;
    }

    return false;
  }
};
