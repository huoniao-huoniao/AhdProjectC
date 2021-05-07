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
  mergeSort(nums, 0, numsSize - 1);
  return nums;
}
void mergeSort(int *nums, int start, int end)
{
  if (end <= start)
    return;
  mergeSort(nums, start, start + (end - start) / 2);
  mergeSort(nums, (start + (end - start) / 2) + 1, end);
  for(int i=start;i<=end;i++)
  {
    for(int j=i+1;j<=end;j++)
    {
      if(nums[i]>nums[j])
      {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
      }
    }
  }
}