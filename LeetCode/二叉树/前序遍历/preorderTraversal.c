struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
void foreachTree(struct TreeNode *root, int *num, int *returnSize);
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
  *returnSize = 0;
  int *num = (int *)malloc(sizeof(int) * 2000);
  foreachTree(root, num, returnSize);
  return num;
}
void foreachTree(struct TreeNode *root, int *num, int *returnSize)
{
  if (root == NULL)
    return;
  num[(*returnSize)++] = root->val;
  foreachTree(root->left, num, returnSize);
  foreachTree(root->right, num, returnSize);
}