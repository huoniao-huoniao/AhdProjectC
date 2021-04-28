#include <string.h>
struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
  struct ListNode *strat = headA;
  struct ListNode *end = headB;
  int lenA = 0;
  while (strat != NULL)
  {
    lenA++;
    strat = strat->next;
  }
  int lenB = 0;
  while (end != NULL)
  {
    lenB++;
    end = end->next;
  }
  strat = headA;
  end = headB;
  int lenc = lenA - lenB;
  while (lenc > 0)
  {
    strat = strat->next;
    lenc--;
  }
  while (lenc < 0)
  {
    end = end->next;
    lenc++;
  }
  while (strat != end)
  {
    strat = strat->next;
    end = end->next;
  }
  return strat;
}