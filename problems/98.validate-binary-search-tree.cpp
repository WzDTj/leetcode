#include "../structures/tree_node.cpp"

class Solution {
public:
  bool isValidBST(TreeNode *root) { return valid(root, nullptr, nullptr); }

private:
  bool valid(TreeNode *root, TreeNode *min_node, TreeNode *max_node) {
    if (root == nullptr)
      return true;

    if ((min_node != nullptr && root->val <= min_node->val) ||
        (max_node != nullptr && max_node->val <= root->val))
      return false;

    return valid(root->left, min_node, root) &&
           valid(root->right, root, max_node);
  }
};
