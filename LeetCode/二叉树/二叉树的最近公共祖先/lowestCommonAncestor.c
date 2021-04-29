#include <string.h>
#include <stdlib.h>
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
  if (root == q || root == p || !root)
  {
    return root;
  }
  struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
  struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
  if (left != NULL && right != NULL)
  {
    return root;
  }
  if (left == NULL && right != NULL)
  { /* 左子树未发现p、q、右子树发现p、q */
    return right;
  }
  else if (left != NULL && right == NULL)
  { /* 右子树未发现p、q、左子树发现p、q */
    return left;
  }
  else
  { /* 左、右子树均未发现p、q */
    return NULL;
  }
}
