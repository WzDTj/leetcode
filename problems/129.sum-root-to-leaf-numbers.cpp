#include "../structures/tree_node.cpp"

class Solution {
public:
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }

private:
  int dfs(TreeNode *root, int num) {
    if (root == nullptr)
      return 0;

    int next_num = num * 10 + root->val;

    if (root->left == nullptr && root->right == nullptr)
      return next_num;

    return dfs(root->left, next_num) + dfs(root->right, next_num);
  }
};
