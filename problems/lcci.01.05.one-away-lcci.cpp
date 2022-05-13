#include <string>

using namespace std;

class Solution {
public:
  bool oneEditAway(string first, string second) {
    if (first == second)
      return true;

    int f_length = first.length();
    int s_length = second.length();

    return f_length < s_length ? check(first, second) : check(second, first);
  }

private:
  bool check(string shorter_str, string longer_str) {
    int s_length = shorter_str.length();
    int l_length = longer_str.length();

    if (1 < l_length - s_length)
      return false;

    int count = 0;
    if (s_length == l_length) {
      int i = 0;
      while (i < s_length) {
        if (shorter_str[i] != longer_str[i])
          ++count;

        ++i;
      }
    } else {
      int s_idx = 0, l_idx = 0;
      while (s_idx < s_length && l_idx < l_length) {
        shorter_str[s_idx] != longer_str[l_idx] ? ++count : ++s_idx;
        ++l_idx;
      }
    }

    return count <= 1;
  }
};
