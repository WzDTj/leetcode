#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int r_len = ransomNote.length();
    int m_len = magazine.length();

    if (m_len < r_len)
      return false;

    vector<int> vec(26, 0);

    for (int i = 0; i < m_len; ++i)
      ++vec[magazine[i] - 97];

    for (int i = 0; i < r_len; ++i)
      if (!vec[ransomNote[i] - 97]--)
        return false;

    return true;
  }
};
