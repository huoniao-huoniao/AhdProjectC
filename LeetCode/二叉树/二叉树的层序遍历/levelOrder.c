#include <string.h>
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 10000
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
  if (root == NULL)
  {
    *returnSize = 0;
    return NULL;
  }
  struct TreeNode *Queue[MAX_SIZE];                     //allow a array of queue
  int **res = (int **)malloc(sizeof(int *) * MAX_SIZE); //return array,each level number
  *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_SIZE);
  int start = 0;
  int end = 0;
  int count = 0;
  Queue[end++] = root;
  while (start != end)
  {
    int new_end = end;
    int i = 0;
    res[count] = (int *)malloc(sizeof(int) * (end - start));
    (*returnColumnSizes)[count] = end - start;
    while (start != new_end)
    {
      struct TreeNode *p = Queue[start];
      res[count][i++] = p->val;
      if (p->left != NULL)
      {
        Queue[end++] = p->left;
      }
      if (p->right != NULL)
      {
        Queue[end++] = p->right;
      }
      start++;
    }
    count++;
  }
  *returnSize = count;

  return res;
}