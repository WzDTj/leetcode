#include "../structures/tree_node.cpp"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  // 递归

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> answer;
    traversal(answer, root);
    return answer;
  }

  // 迭代

  // vector<int> preorderTraversal(TreeNode *root) {
  //   if (root == nullptr)
  //     return {};
  //
  //   vector<int> answer;
  //   stack<TreeNode *> stack({root});
  //
  //   while (!stack.empty()) {
  //     TreeNode *front = stack.top();
  //     stack.pop();
  //
  //     answer.push_back(front->val);
  //     if (front->right != nullptr)
  //       stack.push(front->right);
  //     if (front->left != nullptr)
  //       stack.push(front->left);
  //   }
  //
  //   return answer;
  // }
private:
  void traversal(vector<int> &answer, TreeNode *root) {
    if (root == nullptr)
      return;

    answer.push_back(root->val);
    traversal(answer, root->left);
    traversal(answer, root->right);
  }
};
