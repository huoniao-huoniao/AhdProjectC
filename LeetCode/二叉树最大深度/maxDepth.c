
// Definition for a binary tree node.
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#include <string.h>
int maxDepth(struct TreeNode *root)
{
  if (root == NULL)
    return 0;
  else
  {
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    return leftMax >= rightMax ? leftMax + 1 : rightMax + 1;
  }
}