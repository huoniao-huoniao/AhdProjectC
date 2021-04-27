void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int temp = 0;
    //水平翻转
    for (int i = 0; i < matrixSize / 2; ++i)
    {
        for (int j = 0; j < (*matrixColSize); ++j)
        {
            temp = *(&matrix[i][j]);
            *(&matrix[i][j]) = *(&matrix[(*matrixColSize) - i - 1][j]);
            *(&matrix[(*matrixColSize) - i - 1][j]) = temp;
        }
    }
    //对角线翻转
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            temp = *(&matrix[i][j]);
            *(&matrix[i][j]) = *(&matrix[j][i]);
            *(&matrix[j][i]) = temp;
        }
    }
}