#include "../structures/tree_node.cpp"

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *smaller_node = p->val < q->val ? p : q;
    TreeNode *bigger_node = p->val < q->val ? q : p;

    if (root->val < smaller_node->val)
      return lowestCommonAncestor(root->right, p, q);
    else if (bigger_node->val < root->val)
      return lowestCommonAncestor(root->left, p, q);
    else
      return root;
  }
};
