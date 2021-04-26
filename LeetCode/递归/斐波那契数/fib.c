//递归
static int num[31] = {-1};
int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (num[n] > 0)
    return num[n];
  int fibbNum = fib(n - 1) + fib(n - 2);
  num[n] = fibbNum;
  return fibbNum;
}