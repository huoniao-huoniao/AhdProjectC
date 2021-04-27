#include <math.h>
void QuickSort(int *nums, int start, int end);
int arrayPairSum(int *nums, int numsSize)
{

    if (numsSize <= 0)
        return 0;
    QuickSort(nums, 0, numsSize - 1);
    int sum = 0;
    for (int i = 0; i < numsSize - 1; i = i + 2)
    {
        sum += nums[i];
    }

    return sum;
}

void QuickSort(int *nums, int start, int end)
{
    if (start >= end)
        return;
    int i = start;
    int j = end;
    int temp = 0;
    int proiv = nums[start];
    while (i < j)
    {
        while (nums[j] > proiv && i < j)
            j--;
        nums[i] = nums[j];
        while (nums[i] <= proiv && i < j)
            i++;
        nums[j] = nums[i];
    }
    nums[i] = proiv;
    QuickSort(nums, start, i - 1);
    QuickSort(nums, i + 1, end);
    return;
}