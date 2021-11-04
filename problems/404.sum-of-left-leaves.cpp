#include "../structures/tree_node.cpp"

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr)
      return 0;

    int l_val = root->left != nullptr &&root->left->left ==
                        nullptr &&root->left->right == nullptr
                    ? l_val = root->left->val
                    : sumOfLeftLeaves(root->left);

    return l_val + sumOfLeftLeaves(root->right);
  }
};
