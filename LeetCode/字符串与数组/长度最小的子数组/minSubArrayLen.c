/*
[2,3,1,2,4,3]
*/
#define min (end - start + 1 < lenght ? end - start + 1 : lenght);
int minSubArrayLen(int target, int *nums, int numsSize)
{
    int start = 0;
    int end = 0;
    int sum = 0;
    int lenght = numsSize + 1;
    while (end < numsSize)
    {
        sum += nums[end];
        while (sum >= target)
        {
            lenght = min;
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return lenght == numsSize + 1 ? 0 : lenght;
}