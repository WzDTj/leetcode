#include "../structures/tree_node.cpp"

class Solution {
public:
  bool evaluateTree(TreeNode *root) {
    switch (root->val) {
    case 2:
      return evaluateTree(root->left) | evaluateTree(root->right);
    case 3:
      return evaluateTree(root->left) & evaluateTree(root->right);
    default:
      return root->val;
    }
  }
};
