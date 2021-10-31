#include "../structures/tree_node.cpp"

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    return check(root, targetSum, 0) || check(root, targetSum, 0);
  }

private:
  bool check(TreeNode *node, int target, int current) {
    if (node == nullptr)
      return false;

    int sum = current + node->val;

    if (node->left == nullptr && node->right == nullptr)
      return target == sum;
    else
      return check(node->left, target, sum) || check(node->right, target, sum);
  }
};
