char *CommonPrefix(char *first, char *second);
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return "\0";
    if (strsSize == 1)
        return strs[0];
    char *Left = (char *)malloc(sizeof(char) * 200);
    char *Right = (char *)malloc(sizeof(char) * 200);
    Left = &(strs[0][0]);
    for (int i = 0; i < strsSize; i++)
    {
        if (i + 1 >= strsSize)
            break;
        Right = &(strs[i + 1][0]);
        Left = CommonPrefix(Left, Right);
    }
    return Left;
}

char *CommonPrefix(char *first, char *second)
{
    char *Prefix = (char *)malloc(sizeof(char) * 200);
    for (int i = 0; i < 210; i++)
    {
        if (first[i] == '\0')
        {
            Prefix[i] = '\0';
            break;
        }
        if (second[i] == '\0')
        {
            Prefix[i] = '\0';
            break;
        }
        if (first[i] == second[i])
            Prefix[i] = first[i];
        else
        {
            Prefix[i] = '\0';
            break;
        }
    }
    return Prefix;
}