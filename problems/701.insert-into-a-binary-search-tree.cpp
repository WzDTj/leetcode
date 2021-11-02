#include "../structures/tree_node.cpp"

class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *current = root;

    while (current != nullptr) {
      if (val < current->val) {
        if (current->left == nullptr) {
          current->left = new TreeNode(val);
          return root;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == nullptr) {
          current->right = new TreeNode(val);
          return root;
        } else {
          current = current->right;
        }
      }
    }

    return new TreeNode(val);
  }
};
