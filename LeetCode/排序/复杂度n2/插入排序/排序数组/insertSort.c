/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
void swap(int *nums, int i, int j);
int *insertSort(int *nums, int numsSize, int *returnSize)
{
  *returnSize = numsSize;
  if (numsSize == 0)
    return NULL;
  if (numsSize == 1)
    return nums;
  for (int i = 1; i < numsSize; i++)
  {
    int j = i - 1;
    while (j >= 0 && nums[i] < nums[j])
    {
      swap(nums, i, j);
      i=j;
      j--;
    }
  }
  return nums;
}

void swap(int *nums, int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}