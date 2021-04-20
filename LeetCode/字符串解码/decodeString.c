char * decodeString(char * s){
    //字符串栈
    char * stack=(char *)malloc(sizeof(char)*5000);
    int top=-1;
    //数值字符
    char * mul=(char * )malloc(sizeof(char)*5);
    memset(mul,0,sizeof(char)*5);
    int mulSize=-1;
    //复制字符串临时
    char * str=(char *)malloc(sizeof(char)*500);
    int strTop=-1;
    //数值栈
    int * numStack=(int *)malloc(sizeof(int)*20);
    int numStop=-1;
    for(int i=0;i<strlen(s);i++){
           if((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A')){
                   stack[++top]=s[i];
           }
           else if (s[i]<='9'&&s[i]>='0'){
                mul[++mulSize]=s[i];
           }
           else if(s[i]=='['){
                numStack[++numStop]=atoi(mul);
                stack[++top]=s[i];
                mulSize=-1;
           }
           else{
               int num=numStack[numStop--];
               while(top>=0&&stack[top]!='['){
                   str[++strTop]=stack[top--];
               }
               for(int i=0;i<num;i++){
                   for(int j=strTop;j>=0;j--){
                        stack[top++]=str[j];
                   }
               }
               top--;
               memset(mul,0,sizeof(char)*5);
               mulSize=-1;
               strTop=-1;
           }
    }
    stack[++top]='\0';
    return stack;
}