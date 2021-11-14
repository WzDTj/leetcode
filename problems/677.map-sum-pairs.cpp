#include <string>
#include <unordered_map>

using namespace std;

// 前缀哈希映射

class MapSum {
  unordered_map<string, int> map;
  unordered_map<string, int> prefix_map;

public:
  MapSum() {}

  void insert(string key, int val) {
    int delta = val - map[key];
    map[key] += delta;

    for (int i = 0; i < key.size(); ++i) {
      string sub = key.substr(0, i + 1);
      prefix_map[sub] += delta;
    }
  }

  int sum(string prefix) { return prefix_map[prefix]; }
};

// 暴力
//
// class MapSum {
//   unordered_map<string, int> map;
//
// public:
//   MapSum() {}
//
//   void insert(string key, int val) { map[key] = val; }
//
//   int sum(string prefix) {
//     int prefix_length = prefix.length();
//
//     int result = 0;
//
//     for (auto [key, value] : map) {
//       result += hasPrefix(key, prefix) ? value : 0;
//     }
//
//     printf("%d\n", result);
//     return result;
//   }
//
// private:
//   bool hasPrefix(string s, string prefix) {
//     int n = prefix.length();
//     if (s.length() < n)
//       return false;
//
//     for (int i = 0; i < n; ++i)
//       if (s[i] != prefix[i])
//         return false;
//
//     return true;
//   }
// };
