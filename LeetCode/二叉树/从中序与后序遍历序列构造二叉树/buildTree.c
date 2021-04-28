/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize);
struct TreeNode *buildNode(int *inorder, int inorserStart, int inorderEnd, int *postorder, int postorderStart, int postorderEnd);
int findArraySize(int val, int *array, int start, int end);
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
  return buildNode(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}

struct TreeNode *buildNode(int *inorder, int inorserStart, int inorderEnd, int *postorder, int postorderStart, int postorderEnd)
{
  if (inorderEnd < 0 || postorderEnd < 0 || inorserStart > inorderEnd)
    return NULL;
  if (inorserStart == inorderEnd)
  {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = inorder[inorserStart];
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->val = postorder[postorderEnd];
  int i = findArraySize(root->val, inorder, inorserStart, inorderEnd);
  root->left = buildNode(inorder, inorserStart, i - 1, postorder, postorderStart, (i - 1) - inorserStart + postorderStart);
  root->right = buildNode(inorder, i + 1, inorderEnd, postorder, (postorderEnd - 1) - (inorderEnd - i - 1), postorderEnd - 1);
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