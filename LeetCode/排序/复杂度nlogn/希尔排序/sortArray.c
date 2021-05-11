/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
int *sortArray(int *nums, int numsSize, int *returnSize)
{
  *returnSize = numsSize;
  if (numsSize == 0 || numsSize == 1)
    return nums;
  int arrayNum[5] = {10, 5, 3, 2, 1}; //定义希尔排序的增量数组
  for (int i = 0; i < 5; i++)
  {
    if (arrayNum[i] > numsSize)
      continue;
    for (int j = 0; j < numsSize; j = j + arrayNum[i])
    {
      int f = j - arrayNum[i];
      while (f >= 0 && nums[f] > nums[j])
      {
        swap(nums, f, i);
        j = f;
        f = f - arrayNum[i];
      }
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