#include <stdio.h>
#include <memory.h>
#include <malloc.h>
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

/*Dsf*/
int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize, int **returnColumnSizes)
{
    int n = imageSize, m = *imageColSize;
    *returnSize = n;
    *returnColumnSizes=imageColSize;

    /*apply stack space*/
    Node *stack = (Node *)malloc(sizeof(Node) * (m + 1) * (n + 1));
    memset(stack, 0, sizeof(Node) * (m + 1) * (n + 1));
    int top = -1; //stack pointer

    stack[++top].x = sr;
    stack[top].y = sc;
    int oldColor = image[sr][sc];
    int arr_x[4] = {-1, 1, 0, 0};
    int arr_y[4] = {0, 0, -1, 1};

    /*visted array*/
    int **isVisted = (int **)malloc(sizeof(int *) * n);
    for (int t = 0; t < n; t++)
    {
        isVisted[t] = (int *)malloc(sizeof(int *) * m);
        memset(isVisted[t], 0, sizeof(int) * m);
    }

    while (top != -1)
    {
        int x = stack[top].x;
        int y = stack[top--].y;
        isVisted[x][y] = 1;
        for (int j = 0; j < 4; j++)
        {
            int new_x = x + arr_x[j];
            int new_y = y + arr_y[j];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && isVisted[new_x][new_y] == 0 && image[new_x][new_y] == oldColor)
            {
                stack[++top].x = new_x;
                stack[top].y = new_y;
                image[new_x][new_y] = newColor;
            }
        }
    }

    return image;
}