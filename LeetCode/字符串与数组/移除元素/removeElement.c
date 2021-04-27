int removeElement(int *nums, int numsSize, int val)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while (j < numsSize && i < numsSize)
    {
        while (i < numsSize && nums[i] != val)
            i++;
        j = i;
        while (j < numsSize && nums[j] == val)
            j++;
        if (j > numsSize - 1)
            break;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    return i;
}