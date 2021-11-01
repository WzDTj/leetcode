#include "../structures/tree_node.cpp"
#include <algorithm>

using namespace std;

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return root;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};
