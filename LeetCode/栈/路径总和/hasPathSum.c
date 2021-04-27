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
#define MAX_SIZE 1000
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
/*allow a stack*/
bool hasPathSum(struct TreeNode *root, int targetSum)
{
  if (root == NULL)
    return false;
  struct TreeNode *Stack[MAX_SIZE];
  int stackNum[MAX_SIZE];
  int end = -1;
  Stack[++end] = root;
  stackNum[end] = root->val;
  while (end != -1)
  {
    struct TreeNode *p = Stack[end];
    int val = stackNum[end];
    if (!p->left && !p->right && stackNum[end] == targetSum)
    {
      return true;
    }
    end--; //出栈
    if (p->left)
    {
      Stack[++end] = p->left;
      stackNum[end] = p->left->val + val;
    }
    if (p->right)
    {
      Stack[++end] = p->right;
      stackNum[end] = p->right->val + val;
    }
  }
  return false;
}
