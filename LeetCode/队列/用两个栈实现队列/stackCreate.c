#include <string.h>
typedef struct
{
    int *stack_arr;
    int top;
    int max_lenght;
} stack;

typedef struct
{
    stack *Queue_Append;
    stack *Queue_Delete;
} CQueue;

stack *stackCreate(int max);
stack *stack_push(stack *s, int value);
int stack_pop(stack *s);
CQueue *cQueueCreate();
int cQueueDeleteHead(CQueue *obj);
void cQueueAppendTail(CQueue *obj, int value);

stack *stackCreate(int max)
{
    stack *s = (stack *)malloc(sizeof(stack) * 1);
    s->top = -1;         //栈顶
    s->max_lenght = max; //栈长度
    int *arr = (int *)malloc(sizeof(int) * max);
    s->stack_arr = arr;
    return s;
}

stack *stack_push(stack *s, int value)
{
    if (s->top == s->max_lenght - 1)
        return s;
    s->stack_arr[++(s->top)] = value;
    return s;
}

int stack_pop(stack *s)
{
    if (s->top == -1)
        return -1;
    return s->stack_arr[s->top--];
}
//--------------------------------------------------------------------------------------------------------------

CQueue *cQueueCreate()
{
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue) * 1);
    queue->Queue_Append = stackCreate(5000);
    queue->Queue_Delete = stackCreate(5000);
    return queue;
}

void cQueueAppendTail(CQueue *obj, int value)
{
    if (obj == NULL)
        return;
    if (obj->Queue_Append->top < obj->Queue_Append->max_lenght - 1) //判断栈是否满栈
        stack_push(obj->Queue_Append, value);                       //不满直接入栈
    else
    {
        while (obj->Queue_Append->top != -1)
        {
            stack_push(obj->Queue_Delete, stack_pop(obj->Queue_Append));
        }
        stack_push(obj->Queue_Append, value);
    }
}

int cQueueDeleteHead(CQueue *obj)
{
    if (obj->Queue_Delete->top >= 0)
        return stack_pop(obj->Queue_Delete);
    else
    {
        while (obj->Queue_Append->top != -1)
            stack_push(obj->Queue_Delete, stack_pop(obj->Queue_Append));
        return stack_pop(obj->Queue_Delete);
    }
}

void cQueueFree(CQueue *obj)
{
    free(obj->Queue_Append);
    free(obj->Queue_Delete);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/