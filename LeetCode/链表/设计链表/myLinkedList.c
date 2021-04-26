#include <string.h>
struct Node
{
  int val;
  struct Node *Next;
};
typedef struct Node MyLinkedList;
/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate()
{
  MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList) * 1);
  head->Next = NULL;
  head->val = 0;
  return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1.*/
int myLinkedListGet(MyLinkedList *obj, int index)
{
  if (index < 0 || obj == NULL)
    return -1;
  MyLinkedList *cur = obj->Next;
  int length = 0;
  while (cur != NULL)
  {
    if (length == index)
      return cur->val;
    cur = cur->Next;
    length++;
  }
  return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
  if (obj == NULL)
    return;
  MyLinkedList *New_node = (MyLinkedList *)malloc(sizeof(MyLinkedList) * 1);
  New_node->Next = obj->Next;
  New_node->val = val;
  obj->Next = New_node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
  if (obj == NULL || val <= 0)
    return;
  MyLinkedList *Tail = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  Tail->val = val;
  Tail->Next = NULL;
  MyLinkedList *Cur = obj;
  while (Cur->Next != NULL)
    Cur = Cur->Next;
  Cur->Next = Tail;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
//1.index<0 插入头节点之前 obj之后
//2.index>=0  1.超过长度 不做处理  2.范围内插入当前节点之前  3.等于长度 插入末尾
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
  if (obj == NULL)
    return;
  if (index <= 0)
  { //index<0 1.头节点有下节点  头节点没有下节点
    MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList) * 1);
    head->val = val;
    obj->Next = head;
    if (obj->Next == NULL)
      head->Next = NULL;
    else
      head->Next = obj->Next;
    return;
  }
  else
  {
    MyLinkedList *cur = obj->Next;
    MyLinkedList *pre = obj;
    int lenght = 0;
    while (cur != NULL)
    {
      if (index == lenght && cur->Next != NULL)
      {
        MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList) * 1);
        Node->val = val;
        pre->Next = Node;
        Node->Next = cur;
      }
      if (index == lenght && cur->Next == NULL)
      {
        MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList) * 1);
        Node->val = val;
        Node->Next = NULL;
        cur->Next = Node;
      }
      lenght++;
      cur = cur->Next;
    }
    return;
  }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
  if (obj == NULL || index < 0)
    return;
  MyLinkedList *cur = obj->Next;
  MyLinkedList *pre = obj;
  int length = 0;
  while (cur != NULL)
  {
    if (length == index)
    {
      pre->Next = cur->Next;
      free(cur);
      break;
    }
    pre = cur;
    cur = cur->Next;
    length++;
  }
}

void myLinkedListFree(MyLinkedList *obj)
{
  MyLinkedList *cur = obj;
  MyLinkedList *pre = obj;
  while (cur->Next != NULL)
  {
    cur = cur->Next;
    free(pre);
    pre = cur;
  }
  free(cur);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/