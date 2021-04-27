int pivotIndex(int *nums, int numsSize)
{
    if (numsSize == 0)
        return -1;
    if (numsSize == 1)
        return 0;
    int left = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int right = 0;
        if (i != 0)
            left += nums[i - 1];
        for (int j = i + 1; j < numsSize; j++)
        {
            right += nums[j];
        }
        if (left == right)
            return i;
    }
    return -1;
}