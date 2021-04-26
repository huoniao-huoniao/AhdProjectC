
// Definition for singly-linked list.
struct ListNode
{
  int val;
  struct ListNode *next;
};
#include <string.h>


struct ListNode *mergeTwoLists2(struct ListNode *l1, struct ListNode *l2)
{
  if (l1 == NULL)
    return l2;
  else if (l2 == NULL)
    return l1;
  else if (l1->val >= l2->val)
  {
    l2->next = mergeTwoLists2(l1, l2->next);
    return l2;
  }
  else
  {
    l1->next = mergeTwoLists2(l1->next, l2);
    return l1;
  }
}