#include <string.h>
//Definition for a binary tree node.
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
typedef int bool;
#define true 1
#define false 0
#define Min -2147483648
#define Max 2147483647

bool isValidBST(struct TreeNode *root)
{
  return BST(root, Min, Max);
}

bool BST(struct TreeNode *root, int low, int top)
{
  if (root == NULL)
    return true;
  if (root->val >= top || root->val <= low)
    return false;
  bool left = BST(root->left, Min, root->val);
  bool right = BST(root->right, root->val, Max);
  return left && right;
}
