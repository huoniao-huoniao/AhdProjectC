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
typedef int bool;
#define true 1;
#define false 0;
bool hasCycle(struct ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return false;
  struct ListNode *fast = head->next;
  struct ListNode *slow = head;
  while (fast != slow)
  {
    if (fast == NULL || fast->next == NULL)
      return false;
    slow = slow->next;
    fast = fast->next->next;
  }
  return true;
}