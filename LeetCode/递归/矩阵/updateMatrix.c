/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct
{
  int x;
  int y;
} Node;
int **updateMatrix(int **matrix, int matrixSize, int *matrixColSize, int *returnSize, int **returnColumnSizes)
{
  //define return value
  int m = matrixSize, n = (*matrixColSize);
  *returnSize = m;
  *returnColumnSizes = matrixColSize;

  //return Array
  int **matrixArr = (int **)malloc(sizeof(int *) * m);
  for (int t = 0; t < m; t++)
  {
    matrixArr[t] = (int *)malloc(sizeof(int) * n);
    memset(matrixArr[t], 1000001, sizeof(int) * n);
  }

  int arr_x[4] = {-1, 1, 0, 0};
  int arr_y[4] = {0, 0, 1, -1};
  //Bsf  malloc queue sizem*n
  Node *queue = (Node *)malloc(sizeof(Node) * m * n);
  int end = 0;
  int start = 0;
  //It find a number equal to 0 add the queue
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == 0)
      {
        queue[end].x = i;
        queue[end++].y = j;
        matrixArr[i][j] = 0;
      }
    }
  }

  while (start != end)
  {
    for (int f = 0; f < 4; f++)
    {
      int new_x = queue[start].x + arr_x[f];
      int new_y = queue[start].y + arr_y[f];
      if (
          new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && (matrixArr[queue[start].x][queue[start].y] + 1 < matrixArr[new_x][new_y]))
      {
        matrixArr[new_x][new_y] = matrixArr[queue[start].x][queue[start].y] + 1;
        queue[end].x = new_x;
        queue[end++].y = new_y;
      }
    }
    start++;
  }
  return matrixArr;
}