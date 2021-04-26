#include <string.h>
// Definition for singly-linked list.
struct ListNode
{
  int val;
  struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;
  struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode) * 1); //头节点
  head->val = -1;
  head->next = NULL;
  struct ListNode *l1_cur = l1;
  struct ListNode *l2_cur = l2;
  struct ListNode *cur = head; //遍历指针
  while (l1_cur != NULL || l2_cur != NULL)
  {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
    node->next = NULL;
    if (l1_cur == NULL || (l1_cur != NULL && l2_cur != NULL && l1_cur->val > l2_cur->val))
    {
      node->val = l2_cur->val;
      cur->next = node;
      l2_cur = l2_cur->next;
    }
    else
    {
      node->val = l1_cur->val;
      cur->next = node;
      l1_cur = l1_cur->next;
    }
    cur = cur->next;
  }
  cur = head->next;
  free(head);
  return cur;
}