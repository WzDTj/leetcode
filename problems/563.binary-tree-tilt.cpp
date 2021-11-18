#include "../structures/tree_node.cpp"

class Solution {
public:
  int findTilt(TreeNode *root) {
    int answer = 0;
    traversal(root, answer);
    return answer;
  }

private:
  int traversal(TreeNode *root, int &tilt_sum) {
    if (root == nullptr)
      return 0;

    int left = traversal(root->left, tilt_sum);

    int right = traversal(root->right, tilt_sum);

    tilt_sum += left < right ? right - left : left - right;

    return left + right + root->val;
  }
};
