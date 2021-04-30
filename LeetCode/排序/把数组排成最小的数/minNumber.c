#include <stdio.h>
typedef int bool;
#define ture 1;
#define flase 0;
char *minNumber(int *nums, int numsSize)
{
  for (int i = 0; i < numsSize - 1; i++)
  {
    for (int j = 0; j < numsSize - 1 - i; j++)
    {
      swap(nums, i, j);
    }
  }
}

bool isSwap(int num, int nums)
{
  
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}