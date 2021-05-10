/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
int *sortArray(int *nums, int numsSize, int *returnSize)
{
  *returnSize = numsSize;
  if (numsSize == 0)
    return NULL;
  for (int i = 0; i < numsSize; i++)
  {
    int index = i; //记录最小索引
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[index] > nums[j])
        index = j;
    }
    if (index != i)
    {
      int temp = nums[index];
      nums[index] = nums[i];
      nums[i] = temp;
    }
  }
  return nums;
}