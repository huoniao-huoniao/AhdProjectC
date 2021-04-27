int searchInsert(int *nums, int numsSize, int target)
{

    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0 && target < nums[i])
            return 0;
        if (i == numsSize - 1 && target > nums[i])
            return i + 1;
        if (nums[i] == target)
            return i;
        if (target > nums[i] && target < nums[i + 1])
            return i + 1;
    }
    return 0;
}