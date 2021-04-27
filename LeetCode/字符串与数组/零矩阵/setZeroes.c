void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    //申请一个矩阵
    int **new_matrix = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
        new_matrix[i] = (int *)malloc(sizeof(int) * (*matrixColSize));
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < (*matrixColSize); ++j)
        {
            if ((*(&matrix[i][j])) == 0)
            {
                *(&new_matrix[i][j]) = 1;
            }
        }
    }
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < (*matrixColSize); ++j)
        {
            if (*(&new_matrix[i][j]) == 1)
                setZero(matrix, matrixSize, matrixColSize, i, j);
        }
    }
}

//把第i行的元素所在行列清0
void setZero(int **new_matrix, int matrixSize, int *matrixColSize, int i, int j)
{
    //行清0
    for (int w = 0; w < (*matrixColSize); ++w)
        *(&new_matrix[i][w]) = 0;
    //列清0
    for (int t = 0; t < matrixSize; ++t)
        *(&new_matrix[t][j]) = 0;
}
