#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
  return buildNode(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}

struct TreeNode *buildNode(int *preorder, int preorderStart, int preorderEnd, int *inorder, int inorderStart, int inorderEnd)
{
  if (preorderEnd < 0 || inorderEnd < 0 || inorderStart > inorderEnd)
    return NULL;
  if (inorderStart == inorderEnd)
  {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = inorder[inorderStart];
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->val = preorder[preorderStart];
  int i = findArraySize(root->val, inorder, inorderStart, inorderEnd);
  root->left = buildNode(preorder, preorderStart + 1, preorderStart + 1 + (i - 1 - inorderStart), inorder, inorderStart, i - 1);
  root->right = buildNode(preorder, preorderEnd - (inorderEnd - (i + 1)), preorderEnd, inorder, i + 1, inorderEnd);
  return root;
}

int findArraySize(int val, int *array, int start, int end)
{
  for (int i = start; i <= end; i++)
  {
    if (array[i] == val)
      return i;
  }
  return -1;
}
