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
int rootMax(struct TreeNode *root);
int rootMin(struct TreeNode *root);
struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
  if (root == NULL)
    return root;
  //由于二叉搜索树在数组中递增的
  if (key < root->val)
    root->left = deleteNode(root->left, key);
  if (key > root->val)
    root->right = deleteNode(root->right, key);
  if (key == root->val)
  {
    if (root->left == NULL && root->right == NULL)
      return NULL;
    else if (root->right != NULL)
    {
      root->val = rootMax(root);
      root->right = deleteNode(root->right, root->val);
    }
    else
    {
      root->val = rootMin(root);
      root->left = deleteNode(root->left, root->val);
    }
  }
  return root;
}

int rootMax(struct TreeNode *root)
{
  root = root->right;
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root->val;
}
int rootMin(struct TreeNode *root)
{
  root = root->left;
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root->val;
}