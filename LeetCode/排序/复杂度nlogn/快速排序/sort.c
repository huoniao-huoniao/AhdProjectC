/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *nums, int i, int j);
int divideArray(int *nums, int start, int end);
void quickSort(int *nums, int start, int end);
int *sortArray(int *nums, int numsSize, int *returnSize)
{
  *returnSize = numsSize;
  //快速排序
  quickSort(nums, 0, numsSize - 1);
  return nums;
}
void quickSort(int *nums, int start, int end)
{
  if (start >= end)
    return;
  int middle = divideArray(nums, start, end);
  quickSort(nums, start, middle - 1);
  quickSort(nums, middle + 1, end);
}

int divideArray(int *nums, int start, int end)
{

  int povit = nums[start]; //基数
  int right = end;         //
  int left = start + 1;
  while (left < right)
  {
    while (left < right && nums[left] <= povit)
    {
      left++;
    }
    if (left != right)
    {
      swap(nums, left, right);
      right--;
    }
  }
  if (right == left && nums[right] > povit)
    right--;
  if (right != start)
    swap(nums, start, right);
  return right;
}

void swap(int *nums, int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}