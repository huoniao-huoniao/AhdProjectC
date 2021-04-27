int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while (i < numsSize && j < numsSize)
    {
        while (i < numsSize && nums[i] != 1)
            i++;
        j = i;
        while (j < numsSize && nums[j] == 1)
            j++;
        if ((j - i) > temp)
            temp = j - i;
        i = j;
        j++;
    }
    return temp;
}