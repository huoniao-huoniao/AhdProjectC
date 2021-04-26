#include <string.h>
/*create a struct 
symbol x is coordinate 
symbol y is coordinate
symbol lenght is distance
 */
typedef struct
{
  int x;
  int y;
  int lenght;
} Node;

void wallsAndGates(int **rooms, int roomsSize, int *roomsColSize)
{
  int row = roomsSize;
  int col = *roomsColSize;
  if (row == 0 || col == 0)
    return;
  Node *queue = (Node *)malloc(sizeof(Node) * col * row);
  int start = 0;
  int end = 0;
  int xMov[4] = {0, 0, -1, 1}; //上下左右
  int yMov[4] = {-1, 1, 0, 0}; //上下左右
  int x;
  int y;
  int xx;
  int yy;
  int leng;
  /*把门的坐标结构入队列*/
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      int tt = rooms[i][j];
      if (rooms[i][j] == 0)
      {
        queue[end].x = i;
        queue[end].y = j;
        queue[end++].lenght = 0;
      }
    }
  }
  while (start != end)
  {
    x = queue[start].x;
    y = queue[start].y;
    leng = queue[start++].lenght;
    for (int i = 0; i < 4; i++)
    {
      xx = x + xMov[i];
      yy = y + yMov[i];
      if (xx >= 0 && xx < row && yy >= 0 && yy < col && rooms[xx][yy] == INT_MAX)
      {
        rooms[xx][yy] = leng + 1;
        queue[end].x = xx;
        queue[end].y = yy;
        queue[end++].lenght = leng + 1;
      }
    }
  }
  return;
}