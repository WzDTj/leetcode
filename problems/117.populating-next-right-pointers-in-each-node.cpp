#include <queue>

using namespace std;

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr)
      return root;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        Node *node = q.front();
        q.pop();

        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);

        node->next = i == size - 1 ? nullptr : q.front();
      }
    }

    return root;
  }
};
