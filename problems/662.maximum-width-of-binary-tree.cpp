#include "../structures/tree_node.cpp"
#include <queue>

using namespace std;

class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 1});

    int answer = 0;

    while (!q.empty()) {
      int size = q.size();
      long long l = q.front().second;
      long long r = q.back().second;

      answer = max(answer, (int)(r - l + 1));

      for (int i = 0; i < size; ++i) {
        auto [node, position] = q.front();
        q.pop();

        if (node->left != nullptr) {
          q.push({node->left, (position - l) * 2 - 1});
        }
        if (node->right != nullptr) {
          q.push({node->right, (position - l) * 2});
        }
      }
    }

    return answer;
  }
};
