#include <stddef.h>

//Definition for singly-linked list.
struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
  swapLink(head);
  return head;
}

void swapLink(struct ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return;
  int swap = head->next->val;
  head->next->val = head->val;
  head->val = swap;
  swapLink(head->next->next);
}
