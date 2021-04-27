char *replaceSpace(char *s)
{
    int i = 0;
    int j = 0;
    char *res = (char *)calloc(10000, 1);
    while (i < strlen(s))
    {
        if (s[i] != ' ')
            res[j++] = s[i++];
        else
        {
            res[j++] = '%';
            res[j++] = '2';
            res[j++] = '0';
            i++;
        }
    }
    res[j] = '\0';

    return res;
}