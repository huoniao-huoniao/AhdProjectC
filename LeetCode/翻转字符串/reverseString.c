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

void reverseString2(char * s,int sSize){
     reverseHelp(s,0,sSize-1);
}
void reverseHelp(char * s,int start,int end){
      if(start>end){
        return;
      }
      char swap=s[start];
      s[start]=s[end];
      s[end]=swap;
      reverseHelp(s,start+1,end-1);
}