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

bool hasPathSum(struct TreeNode *root, int targetSum)
{
  if (!root)
    return false;
  if (!root->left && !root->right && targetSum == root->val)
    return true;
  return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
}
