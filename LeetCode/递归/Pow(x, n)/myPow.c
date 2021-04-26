
double myPow(double x, int n)
{
  if (n >= 0)
  {
    if (n == 0)
      return 1;
    else if (n % 2 == 0)
      return myPow(x, n >> 1) * myPow(x, n >> 1);
    else
      return myPow(x, n >> 1) * myPow(x, n >> 1) * x;
  }
  else
    return myPow(1 / x, -(n + 1)) * (1 / x);
}