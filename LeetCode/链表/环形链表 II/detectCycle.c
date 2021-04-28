#include <string.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};
typedef int bool;
#define true 1;
#define false 0;
struct ListNode *detectCycle(struct ListNode *head)
{
  if (head == NULL)
    return NULL;
  struct ListNode *fast = head->next;
  struct ListNode *slow = head;
  while (fast != NULL && fast->next != NULL)
  {
    if (fast == slow)
    {
      struct ListNode *Cur = head;
      slow = slow->next;
      while (slow != Cur)
      {
        while (slow != fast)
        {
          if (slow == Cur)
            return Cur;
          slow = slow->next;
        }
        Cur = Cur->next;
        slow = slow->next;
      }
      return slow;
    }
    fast = fast->next->next;
    slow = slow->next;
  }
  return NULL;
}