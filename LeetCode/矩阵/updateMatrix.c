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
    memset(matrixArr[t], 0, sizeof(int) * n);
  }

  int arr_x[4] = {-1, 1, 0, 0};
  int arr_y[4] = {0, 0, 1, -1};
  //Bsf  malloc queue sizem*n
  Node *queue = (Node *)malloc(sizeof(Node) * m * n);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int start = 0;
      int end = 1;
      if (matrix[i][j] != 0)
      {
        queue[start].x = i;
        queue[start].y = j;
        int count = 0;
        //in queue
        while (start != end)
        {
          int new_end = end;
          while (start != new_end)
          {
            for (int f = 0; f < 4; f++)
            {
              int new_x = queue[start].x + arr_x[f];
              int new_y = queue[start].y + arr_y[f];
              int tt = queue[start].y;
              if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n)
              {
                if (matrix[new_x][new_y] != 0)
                {
                  queue[end++].x = new_x;
                  queue[end].y = new_y;
                }
                else
                {
                  end = new_end;
                  break;
                }
              }
            }
            start++;
          }
          count++;
        }
        matrixArr[i][j] = count;
      }
    }
  }
  return matrixArr;
}