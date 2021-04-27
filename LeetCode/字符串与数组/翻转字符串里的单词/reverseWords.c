void reserver(char *s, int start, int end);
char *trim(char *s);
char *reverseWords(char *s)
{
    char *t = trim(s);
    reserver(t, 0, strlen(t) - 1);
    int start = 0;
    int end = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if ((t[i] == ' ' && i - 1 > 0 && t[i - 1] != ' '))
        {
            end = i - 1;
            reserver(t, start, end);
        }
        if (t[i + 1] == '\0')
        {
            end = i;
            reserver(t, start, end);
        }
        if (t[i] == ' ' && i + 1 < strlen(t) && t[i + 1] != ' ')
        {
            start = i + 1;
        }
    }
    return t;
}

void reserver(char *s, int start, int end)
{
    for (int i = start; (i - start) < (end - start + 1) / 2; i++)
    {
        char temp = s[i];
        char tt = s[(end + start) - i];
        s[i] = s[(end + start) - i];
        s[(end + start) - i] = temp;
    }
}
char *trim(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ')
        {
            s = &s[i];
            break;
        }
    }
    for (int j = strlen(s) - 1; j > 0; j--)
    {
        if (s[j] != ' ')
        {
            s[j + 1] = '\0';
            break;
        }
    }
    char *new_str = (char *)malloc(sizeof(char) * 1);
    int index = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ' || (s[i] == ' ' && i - 1 >= 0 && s[i - 1] != ' '))
        {
            new_str[index] = s[i];
            index++;
            new_str = (char *)realloc(new_str, ((index + 1) * sizeof(char)));
        }
    }
    new_str[index] = '\0';
    return new_str;
}