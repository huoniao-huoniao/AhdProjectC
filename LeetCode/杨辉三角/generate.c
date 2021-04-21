/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
  *returnSize = numRows;
  *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
  int **ret = (int **)malloc(sizeof(int *) * numRows);
  for (int i = 0; i < numRows; i++)
  {
    ret[i] = (int *)malloc(sizeof(int) * (i + 1));
    (*returnColumnSizes)[i] = i + 1;
    ret[i][0] = ret[i][i] = 1;
    for (int j = 1; j < i; j++)
    {
      ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
    }
  }
  return ret;
}
//------------------------递归----------------------------------------------------
int **generate2(int numRows, int *returnSize, int **returnColumnSizes)
{
  *returnSize = numRows;
  *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
  int **ret = (int **)malloc(sizeof(int *) * numRows);
  return fillGenerate(ret, 0, numRows, returnColumnSizes);
}

int **fillGenerate(int **ret, int rows, int numRows, int **returnColumnSizes)
{
  if (rows > numRows - 1)
    return ret;
  ret[rows] = (int *)malloc(sizeof(int) * (rows + 1));
  (*returnColumnSizes)[rows] = rows + 1;
  ret[rows][0] = ret[rows][rows] = 1;
  for (int j = 1; j < rows; j++)
  {
    ret[rows][j] = ret[rows - 1][j] + ret[rows - 1][j - 1];
  }
  return fillGenerate(ret, rows + 1, numRows, returnColumnSizes);
}