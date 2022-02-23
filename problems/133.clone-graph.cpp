#include "../structures/graph_node.cpp"
#include <unordered_map>

using namespace std;

class Solution {
public:
  Node *cloneGraph(Node *node) {
    unordered_map<int, Node *> map;

    Node *answer = dfs(node, map);

    return answer;
  }

private:
  Node *dfs(Node *node, unordered_map<int, Node *> &map) {
    if (node == nullptr) {
      return nullptr;
    }

    if (map.count(node->val)) {
      return map[node->val];
    }

    Node *cloned_node = new Node(node->val, {});

    map[node->val] = cloned_node;

    for (auto neighbor : node->neighbors) {
      cloned_node->neighbors.push_back(dfs(neighbor, map));
    }

    return cloned_node;
  }
};
