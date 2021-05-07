//给你一个整数数组 nums，请你将该数组升序排列。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
int *sortArray(int *nums, int numsSize, int *returnSize)
{
  *returnSize = numsSize;
  if (numsSize == 0)
    return NULL;
  mergeSort(nums, 0, numsSize-1);
  return nums;
}
void mergeSort(int *nums, int start, int end)
{
  while (end >= start)
  {
    if (nums[start] > nums[end])
    {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
    }
    end--;
    start++;
  }
  mergeSort(nums, 0, (end - start) / 2);
  mergeSort(nums, (end - start) / 2 + 1, end);
}