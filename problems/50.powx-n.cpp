class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    if (n == 1)
      return x;
    if (n < 0)
      return 1 / myPow(x, -(n + 1)) / x;

    int next_n = n / 2;

    double tmp = myPow(x, next_n);

    double result = tmp * tmp;
    if (n % 2)
      result *= x;

    return result;
  }
};
