static int num[60] = {-1};
int climbStairs(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  if (num[n] > 0)
  {
    return num[n];
  }
  int result = climbStairs(n - 1) + climbStairs(n - 2);
  num[n]=result;
  return result;
}