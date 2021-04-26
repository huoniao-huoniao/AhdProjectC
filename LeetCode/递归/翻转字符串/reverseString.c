
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