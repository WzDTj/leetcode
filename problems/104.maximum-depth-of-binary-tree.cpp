
#include "../structures/tree_node.cpp"
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
