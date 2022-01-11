#include "../structures/tree_node.cpp"

class Solution {
public:
  int sumRootToLeaf(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return recursion(root, 0);
  }

private:
  int recursion(TreeNode *root, int value) {
    int tmp = root->val + (value << 1);

    if (root->left == nullptr && root->right == nullptr) {
      return tmp;
    }

    int left = root->left == nullptr ? 0 : recursion(root->left, tmp);
    int right = root->right == nullptr ? 0 : recursion(root->right, tmp);

    return left + right;
  }
};
