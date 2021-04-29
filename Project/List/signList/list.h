/*list.h*/
#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
typedef struct ListElmt_
{
  void *data;
  struct List(*Next);
} ListElmt;

typedef struct List_
{
  int size;
  int (*match)(const void *key1, const void *key2);
  void (*destory)(void *data);
  ListElmt *head;
  ListElmt *tail;
} List;

/*public interface */
void list_init(List *list, void (*destory)(const void *data));
void list_destory(List *list);
int list_ins_next(List *list, ListElmt *listElem, const void *data);

#endif
