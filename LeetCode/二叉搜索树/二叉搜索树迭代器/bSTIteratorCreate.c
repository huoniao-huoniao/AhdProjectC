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
typedef struct
{
  int *arr;
  int lenght;
  int Flag;
} BSTIterator;
typedef int bool;
#define false 0
#define true 1
int getTreeSize(struct TreeNode *root)
{
  if (root == NULL)
    return 0;
  return 1 + getTreeSize(root->right) + getTreeSize(root->left);
}

void inorder(int *arr, int *lenght, struct TreeNode *root)
{
  if (root == NULL)
    return;
  inorder(arr, lenght, root->left);
  arr[(*lenght)++] = root->val;
  inorder(arr, lenght, root->right);
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root)
{
  BSTIterator *t = (BSTIterator *)malloc(sizeof(BSTIterator));
  t->lenght = 0;
  t->arr = (int *)malloc(sizeof(int) * getTreeSize(root));
  t->Flag = 0;
  inorder(t->arr, &t->lenght, root);
  return t;
}

int bSTIteratorNext(BSTIterator *obj)
{
  return obj->arr[obj->Flag++];
}

bool bSTIteratorHasNext(BSTIterator *obj)
{
  return (obj->Flag - obj->lenght >= 0) ? false : true;
}

void bSTIteratorFree(BSTIterator *obj)
{
  free(obj->arr);
  free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/