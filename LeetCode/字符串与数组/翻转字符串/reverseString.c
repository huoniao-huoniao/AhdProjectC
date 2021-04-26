//double pointer
void reverseString(char *s, int sSize)
{
  int left = 0;
  int right = sSize - 1;
  while (left <= right)
  {
    if (left == right)
      return;
    char temp;
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
  }
}