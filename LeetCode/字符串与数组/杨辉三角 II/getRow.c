/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *arr[1000];
    for (int i = 0; i <= rowIndex; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * (i + 1));
        arr[i][0] = arr[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    return arr[rowIndex];
}