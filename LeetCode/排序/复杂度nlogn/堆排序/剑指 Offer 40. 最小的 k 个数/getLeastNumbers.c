/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *nums, int i, int j);
void buildLeastHead(int *arr, int lenght);
void leastHeadBuild(int *arr, int i, int lenght);
void headSort(int *arr, int lenght, int k);
int *getLeastNumbers(int *arr, int arrSize, int k, int *returnSize)
{
  *returnSize = k;
  headSort(arr, arrSize, k);
  int *res = (int *)malloc(sizeof(int) * k);
  for (int i = 0; i < k; i++)
  {
    res[i] = arr[arrSize - 1 - i];
  }
  return res;
}
void headSort(int *arr, int lenght, int k)
{
  buildLeastHead(arr, lenght);
  for (int i = lenght - 1; i > lenght - k - 1; i--)
  {
    swap(arr, 0, i);
    leastHeadBuild(arr, 0, i);
  }
}

void buildLeastHead(int *arr, int lenght)
{
  for (int i = lenght / 2 - 1; i >= 0; i--)
  {
    leastHeadBuild(arr, i, lenght);
  }
}
//计算单个节点的最大堆
void leastHeadBuild(int *arr, int i, int lenght)
{
  int left = 2 * i + 1;
  int right = left + 1;
  int flag = i;
  if (left < lenght && arr[left] < arr[flag])
    flag = left;
  if (right < lenght && arr[right] < arr[flag])
    flag = right;
  if (flag != i)
  {
    swap(arr, flag, i);
    leastHeadBuild(arr, flag, lenght);
  }
}

void swap(int *nums, int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
