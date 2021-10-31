#include "../structures/tree_node.cpp"

class Solution {
public:
  // 递归

  // bool isSymmetric(TreeNode *root) { return valid(root->left, root->right); }

private:
  bool valid(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr)
      return true;
    else if (left == nullptr || right == nullptr)
      return false;
    else
      return left->val == right->val && valid(left->left, right->right) &&
             valid(left->right, right->left);
  }
};
