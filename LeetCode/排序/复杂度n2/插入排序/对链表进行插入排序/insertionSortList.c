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

struct ListNode *insertionSortList(struct ListNode *head)
{
  if (head == NULL)
    return NULL;
  struct ListNode *dyNode = (struct ListNode *)malloc(sizeof(struct ListNode));
  dyNode->next = head;
  struct ListNode *p = head;       //排序后头指针
  struct ListNode *q = head->next; //待插入的节点
  p->next = NULL;
  struct ListNode *pTail = p; //排序尾指针
  while (q != NULL)
  {
    /*在头部*/
    if (q->val <= p->val)
    {
      dyNode->next = q;
      pTail->next = q->next;
      q->next = p;
      p = dyNode->next;
      q = pTail->next;
      continue;
    }
    /*在尾部*/
    if (q->val >= pTail->val)
    {
      pTail->next = q;
      pTail = pTail->next;
      q = pTail->next;
      continue;
    }
    /*在中间*/
    if (p->val < q->val && q->val < pTail->val)
    {
      p = dyNode->next;
      while (p != pTail)
      {
        if (p->val <= q->val && q->val <= p->next->val)
        {
          pTail->next = q->next;
          q->next = p->next;
          p->next = q;
          q = pTail->next;
          p = dyNode->next;
          break;
        }
        p = p->next;
      }
    }
  }
  return dyNode->next;
}