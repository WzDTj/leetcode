#include <vector>

using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int n = letters.size();

    int l = search(letters, target);

    return letters[l % n];
  }

private:
  int search(vector<char> &letters, char target) {
    int n = letters.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + ((r - l) >> 1);
      letters[m] <= target ? l = m + 1 : r = m;
    }

    return l;
  }
};
