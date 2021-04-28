#include <stdio.h>
#include <string.h>
struct Node
{
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *next;
};
#define MAX_SIZE 4096
struct Node *connect(struct Node *root)
{
  if (root == NULL)
    return NULL;
  struct Node *Queue[MAX_SIZE];
  int start = 0;
  int end = 0;
  Queue[end++] = root;
  root->next = NULL;
  while (start != end)
  {
    int new_end = end;
    int new_start = start;
    while (start != new_end)
    {
      struct Node *p = Queue[start];
      if (p->left && p->right)
      {
        Queue[end++] = p->left;
        Queue[end++] = p->right;
      }
      start++;
    }
    while (new_start != new_end - 1)
    {
      struct Node *p = Queue[new_start];
      p->next = Queue[new_start + 1];
      new_start++;
    }
  }
  return root;
}