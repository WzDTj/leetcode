#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  unordered_map<int, string> map;
  int index = 0;

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    map[index] = longUrl;
    return "http://" + to_string(index++);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) { return map[shortUrl[7] - '0']; }
};
