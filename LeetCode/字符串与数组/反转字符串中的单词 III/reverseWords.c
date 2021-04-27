char *Convert(char *s, int start, int end);
char *reverseWords(char *s)
{
    int i = 0;
    int j = 0;
    int lenght = strlen(s);
    while (j < lenght)
    {
        while (s[i] == ' ')
            i++;
        j = i;
        while (!(s[j] != ' ' && (s[j + 1] == ' ' || s[j + 1] == '\0')))
            j++;
        int start = i;
        int end = j;
        while (start < end)
        {
            char tmp = s[start];
            char tt = s[end];
            s[start] = s[end], s[end] = tmp;
            start++;
            end--;
        }
        i = j + 1;
        j++;
    }
    return s;
}