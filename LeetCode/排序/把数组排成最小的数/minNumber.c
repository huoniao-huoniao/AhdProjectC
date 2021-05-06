#include <string.h>
#define numberSize 20
int sortcmp(char **pre, char **behind);
char *minNumber(int *nums, int numsSize);
void main()
{
  int str[10]={1,3,2,4,35,3,5,245,65,47};
  minNumber(str,10);
}
char *minNumber(int *nums, int numsSize)
{
  if (numsSize == 0)
    return NULL;
  char **nChar = (char **)calloc(numsSize, sizeof(char *));
  for (int i = 0; i < numsSize; i++)
  {
    char *temp = (char *)calloc(numberSize, sizeof(char));
    sprintf(temp, "%d", nums[i]);
    nChar[i] = temp;
  }
  qsort(nChar, numsSize, sizeof(char *), sortcmp);
  char *_st = (char *)calloc(4000, sizeof(char));
  for (int i = 0; i < numsSize; i++)
  {
    strcat(_st, nChar[i]);
  }
  return _st;
}
int sortcmp(char **pre, char **behind)
{
  char *temp1 = (char *)calloc(numberSize, sizeof(char));
  char *temp2 = (char *)calloc(numberSize, sizeof(char));
  strcat(strcat(temp1, *pre), *behind);
  strcat(strcat(temp2, *behind), *pre);
  if (strcmp(temp1, temp2) > 0)
  {
    return 1;
  }
  free(temp1);
  free(temp2);
  return 0;
}