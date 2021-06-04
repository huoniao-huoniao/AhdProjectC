/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

#include <string.h>

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
  if (root == NULL)
    return NULL;
  if (root->val == val)
    return root;
  if (root->val > val)
    return searchBST(root->left, val);
  if (root->val < val)
    return searchBST(root->right, val);
  return NULL;
}