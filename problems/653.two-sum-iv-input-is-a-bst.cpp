#include "../structures/tree_node.cpp"
// #include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    unordered_set<int> set;
    return search(root, k, set);
  }

  // BFS + Binary Search

  // bool findTarget(TreeNode *root, int k) {
  //   queue<TreeNode *> queue({root});
  //
  //   while (!queue.empty()) {
  //     for (int i = 0; i < queue.size(); ++i) {
  //       TreeNode *front = queue.front();
  //       queue.pop();
  //
  //       TreeNode *target_node = search(root, k - front->val);
  //       if (target_node != nullptr && target_node != front)
  //         return true;
  //
  //       if (front->left != nullptr)
  //         queue.push(front->left);
  //       if (front->right != nullptr)
  //         queue.push(front->right);
  //     }
  //   }
  //
  //   return false;
  // }

private:
  TreeNode *search(TreeNode *root, int target) {
    if (root == nullptr)
      return nullptr;

    if (root->val == target)
      return root;

    return search(target < root->val ? root->left : root->right, target);
  }

  bool search(TreeNode *root, int target, unordered_set<int> &set) {
    if (root == nullptr)
      return false;

    auto it = set.find(target - root->val);
    if (it != set.end())
      return true;

    set.insert(root->val);

    return search(root->left, target, set) || search(root->right, target, set);
  }
};
