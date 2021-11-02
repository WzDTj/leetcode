#include "../structures/tree_node.cpp"

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr || root->val == val)
      return root;

    return val < root->val ? searchBST(root->left, val)
                           : searchBST(root->right, val);
  }
};
