#include "../structures/tree_node.cpp"
#include <vector>

using namespace std;

class Solution {
public:
  // 递归

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> answer;
    traversal(answer, root);
    return answer;
  }

  // 迭代

  // vector<int> inorderTraversal(TreeNode *root) {
  // }

private:
  void traversal(vector<int> &answer, TreeNode *root) {
    if (root == nullptr)
      return;

    traversal(answer, root->left);
    answer.push_back(root->val);
    traversal(answer, root->right);
  }
};
