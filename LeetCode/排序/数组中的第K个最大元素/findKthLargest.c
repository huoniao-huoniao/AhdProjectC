int findKthLargest(int *nums, int numsSize, int k)
{
  if (numsSize == 0)
    return -1;
  for (int i = 0; i < k; i++)
  {
    int index = i;
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[index] < nums[j])
      {
        index = j;
      }
    }
    int temp = nums[index];
    nums[index] = nums[i];
    nums[i] = temp;
  }
  return nums[k - 1];
}