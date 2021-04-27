int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int i = 0;
    int j = 0;
    while (j < numsSize)
    {
        if (nums[j] > nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i + 1;
}