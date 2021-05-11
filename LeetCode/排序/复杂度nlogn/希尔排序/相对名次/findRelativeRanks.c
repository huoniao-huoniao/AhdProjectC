/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
char **findRelativeRanks(int *score, int scoreSize, int *returnSize)
{
  *returnSize = scoreSize;
  int *scoreTemp = (int *)malloc(sizeof(int) * scoreSize);
  for (int i = 0; i < scoreSize; i++)
  {
    scoreTemp[i] = score[i];
  }
  char **res = (char **)malloc(sizeof(char *) * scoreSize);
  qsort(score, scoreSize, sizeof(int), cmp);
  int arr[200000];
  for (int i = 0; i < scoreSize; i++)
  {
    arr[score[i]] = i;
  }

  for (int i = 0; i < scoreSize; i++)
  {
    if (arr[scoreTemp[i]] == 0)
    {
      res[i] = (char *)malloc(sizeof(char) * 10);
      res[i] = "Gold Medal";
    }
    else if (arr[scoreTemp[i]] == 1)
    {
      res[i] = (char *)malloc(sizeof(char) * 12);
      res[i] = "Silver Medal";
    }
    else if (arr[scoreTemp[i]] == 2)
    {
      res[i] = (char *)malloc(sizeof(char) * 12);
      res[i] = "Bronze Medal";
    }
    else
    {
      res[i] = (char *)malloc(sizeof(char) * 6);
      sprintf(res[i], "%d", arr[scoreTemp[i]] + 1);
    }
  }
  return res;
}

int cmp(const void *nums1, const void *nums2)
{
  return (*(int *)nums1 - *(int *)nums2);
}