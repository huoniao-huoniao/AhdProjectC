void moveZeroes(int *nums, int numsSize)
{
    int i = 0;
    int j = 0;
    while (j < numsSize)
    {
        while (nums[j] != 0)
        {
            while (i <= j && nums[i] != 0)
                i++;
            break;
        }
        if (i <= j && nums[j] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        j++;
    }
}