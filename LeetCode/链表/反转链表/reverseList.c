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

struct ListNode *reverseList(struct ListNode *head)
{
  if (head == NULL)
    return NULL;
  struct ListNode *start = head->next;
  struct ListNode *Pre = head;
  while (start != NULL)
  {
    head->next = start->next;
    start->next = Pre;
    Pre = start;
    start = head->next;
  }
  return Pre;
}