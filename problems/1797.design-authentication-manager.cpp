#include <string>
#include <unordered_map>

using namespace std;

class AuthenticationManager {
private:
  int timeToLive;
  unordered_map<string, int> map;

public:
  AuthenticationManager(int timeToLive) {
    this->timeToLive = timeToLive;
    map = unordered_map<string, int>();
  }

  void generate(string tokenId, int currentTime) {
    map[tokenId] = currentTime + timeToLive;
  }

  void renew(string tokenId, int currentTime) {
    if (!map.count(tokenId) || map[tokenId] <= currentTime) {
      return;
    }

    map[tokenId] = currentTime + timeToLive;
  }

  int countUnexpiredTokens(int currentTime) {
    int count = 0;

    for (auto [_, expiredTime] : map) {
      count += currentTime < expiredTime;
    }

    return count;
  }
};
