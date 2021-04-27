/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int *Size = (int *)malloc(sizeof(int) * 2);
    Size[0] = 0;
    Size[1] = 0;

    int i = 0;
    int j = numbersSize - 1;
    //numbers[j]<target-numbers[i]
    while (i < j)
    {
        if (numbers[j] == target - numbers[i])
        {
            Size[0] = i + 1;
            Size[1] = j + 1;
            break;
        }
        if (numbers[j] > target - numbers[i])
            j--;
        if (numbers[j] < target - numbers[i])
            i++;
    }
    *returnSize = 2;
    return Size;
}