
char * longestCommonPrefix(char ** strs, int strsSize){
    static char commonStr[200] = {0};
    int i = 0, j = 0;
    int minLen = 0;

    //校验入参为“”的情况
    if (strsSize < 1) return "";
    
    memset(commonStr, 0, 200);
    memcpy(commonStr, strs[0], strlen(strs[0]));

    for (i = 1; i < strsSize; i++)
    {
        minLen = fmin(strlen(commonStr), strlen(strs[i]));
        if (minLen < 1) 
        {
            return "";
        }

        for (j = 0; j < minLen + 1; j++)     //注意：数组边界！！！
        {
            if (commonStr[j] != strs[i][j])
                commonStr[j] = '\0';
        }
    }
    return commonStr;
}
