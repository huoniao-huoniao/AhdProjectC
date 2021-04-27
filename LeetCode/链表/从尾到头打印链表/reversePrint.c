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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *reversePrint(struct ListNode *head, int *returnSize)
{
    if (head == NULL)
    {
        *returnSize = 0;
        int *result = (int *)malloc(sizeof(int) * 10001);
        return result;
    }
    int *result1 = reversePrint(head->next, returnSize);
    result1[(*returnSize)++] = head->val;
    return result1;
}
