void swap(int *nums, int i, int j);
//可以使用堆排序
/*
1.对于一个数组  堆排序   最后的非叶子节点的位置(lengh/2-1),位置从0开始
2.大堆  小堆是指父节点的值大于或小于子节点的值

构建最大堆  找到最大值放入根节点，把根节点与数组的最后的最调换后
在根节点与未节点之前 在进行最大堆构建 重复
知道最大堆的长度为1
*/
void sort(int *nums, int numsSize, int k);
void buildMaxHead(int *nums, int lenght);
void maxHeadSort(int *nums, int i, int lenght);
void swap(int *nums, int i, int j);
int findKthLargest(int *nums, int numsSize, int k)
{
  sort(nums, numsSize, k);
  return nums[0];
}
void sort(int *nums, int numsSize, int k)
{
  //构建最大堆
  buildMaxHead(nums, numsSize);
  for (int i = numsSize - 1; i > numsSize - k; i--)
  {
    swap(nums, 0, i);
    maxHeadSort(nums, 0, i);
  }
}

void buildMaxHead(int *nums, int lenght)
{
  for (int i = lenght / 2 - 1; i >= 0; i--)
  {
    maxHeadSort(nums, i, lenght);
  }
}

//最大堆构建
void maxHeadSort(int *nums, int i, int lenght)
{
  //左节点
  int leftNode = (2 * i) + 1;
  //右节点
  int rightNode = leftNode + 1;
  int large = i;
  if (leftNode < lenght && nums[leftNode] > nums[large])
    large = leftNode;
  if (rightNode < lenght && nums[rightNode] > nums[large])
    large = rightNode;
  if (large != i)
  {
    swap(nums, i, large);
    maxHeadSort(nums, large, lenght);
  }
}

void swap(int *nums, int i, int j)
{
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}