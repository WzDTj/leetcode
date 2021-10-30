#include "../structures/tree_node.cpp"
#include <vector>

using namespace std;

class Solution {
public:
  // 递归

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> answer;
    traversal(answer, root);
    return answer;
  }

  // 迭代

  // vector<int> postorderTraversal(TreeNode *root) {
  // }

private:
  void traversal(vector<int> &answer, TreeNode *root) {
    if (root == nullptr)
      return;

    traversal(answer, root->left);
    traversal(answer, root->right);
    answer.push_back(root->val);
  }
};
