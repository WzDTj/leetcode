#include "../structures/n_tree_node.cpp"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> preorder(Node *root) {
    vector<int> answer;

    if (root == nullptr) {
      return answer;
    }

    stack<Node *> stk;
    stk.push(root);

    while (!stk.empty()) {
      Node *current = stk.top();
      stk.pop();
      answer.emplace_back(current->val);

      for (int i = current->children.size() - 1; 0 <= i; --i) {
        stk.push(current->children[i]);
      }
    }

    return answer;
  }
};
