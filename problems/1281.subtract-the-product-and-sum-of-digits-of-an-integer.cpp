class Solution {
public:
  int subtractProductAndSum(int n) {
    int sum = 0, product = 1;

    while (n) {
      int tmp = n % 10;
      sum += tmp;
      product *= tmp;
      n /= 10;
    }

    return product - sum;
  }
};
