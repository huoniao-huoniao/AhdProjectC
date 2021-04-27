/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <string.h>
typedef int bool;
#define true 1;
#define false 0;
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
bool isSymmetric(struct TreeNode *root)
{
  return checkNode(root, root);
}

bool checkNode(struct TreeNode *p, struct TreeNode *q)
{
  if (q == NULL && p == NULL)
    return true;
  if ((q == NULL && p != NULL) || (q != NULL && p == NULL))
    return false;
  return p->val == q->val && checkNode(p->left, q->right) && checkNode(p->right, q->left);
}
