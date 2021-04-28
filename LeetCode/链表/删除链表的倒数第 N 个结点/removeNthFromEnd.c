/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <string.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
  if (head == NULL)
    return NULL;
  struct ListNode *root = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
  root->next = head;
  root->val = -1;
  struct ListNode *slow = root;
  struct ListNode *fast = root;
  while (n >= 0)
  {
    fast = fast->next;
    n--;
  }
  while (fast != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;

  return root->next;
}