#include <stack>

using namespace std;

class MyQueue {
public:
  stack<int> positive;
  stack<int> reverse;

  MyQueue() {}

  void push(int x) { positive.push(x); }

  int pop() {
    int top = this->peek();
    reverse.pop();
    return top;
  }

  int peek() {
    if (!reverse.empty())
      return reverse.top();

    int n = positive.size();
    for (int i = 0; i < n; ++i) {
      reverse.push(positive.top());
      positive.pop();
    }

    return reverse.top();
  }

  bool empty() { return positive.empty() && reverse.empty(); }
};
