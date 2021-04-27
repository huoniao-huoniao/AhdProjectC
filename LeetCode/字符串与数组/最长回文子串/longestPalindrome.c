#include <string.h>
char *PalindromeString(char *s, int start, int end);
char *longestPalindrome(char *s)
{
    //用二维数组记下字符串区域是否是回文字符串
    int length = strlen(s);
    int index1 = 0;
    int index2 = 0;
    int **arr2 = (int **)malloc(sizeof(int *) * length);
    for (int i = 0; i < length; i++)
        arr2[i] = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((i - j) < 2)
            {
                arr2[j][i] = (int)(s[i] == s[j]);
            }
            else
            {
                arr2[j][i] = (int)(arr2[j + 1][i - 1] && (s[i] == s[j]));
            }
            if (arr2[j][i] && (i - j + 1) > (index2 - index1 + 1))
            {
                index1 = j;
                index2 = i;
            }
        }
    }
    return PalindromeString(s, index1, index2);
}

//截取回文字符串
char *PalindromeString(char *s, int start, int end)
{
    char *new_str = (char *)malloc(sizeof(char) * (end - start + 2));
    int i = 0;
    while (start <= end)
    {
        new_str[i] = s[start];
        start++;
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}