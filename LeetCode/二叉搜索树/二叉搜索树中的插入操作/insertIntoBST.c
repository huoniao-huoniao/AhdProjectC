/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <string.h>
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
void IntoBST(struct TreeNode *root, int val);
void IntoBST(struct TreeNode *root, int val)
{
  if (root->left == NULL && root->val > val)
  {
    struct TreeNode *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = t;
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return;
  }
  if (root->right == NULL && root->val < val)
  {
    struct TreeNode *t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right = t;
    t->val = val;
    t->left = NULL;
    t->right = NULL;
    return;
  }
  if (root->val > val)
    IntoBST(root->left, val);
  if (root->val < val)
    IntoBST(root->right, val);
  return;
}

struct TreeNode *insertIntoBST(struct TreeNode *root, int val)
{
  if (root == NULL)
  {
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  IntoBST(root, val);
  return root;
}