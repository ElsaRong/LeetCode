#define MAX_LEN 200

bool backspaceCompare(char * S, char * T){
    int i = 0;
    int len1 = -1;
    int len2 = -1;
    int s1[MAX_LEN] = {0};
    int s2[MAX_LEN] = {0};
    int top1 = -1;
    int top2 = -1;

    len1 = strlen(S);
    len2 = strlen(T);

    //从第一个不为‘#’的字符开始生成栈
    for(i = 0; i < len1; i++)
    {
        if (S[i] != '#')
        {
            s1[++top1] = S[i];
        }
        else
        {
            if (top1 != -1)
                top1--;
        }
    }
    //生成栈2
    for(i = 0; i < len2; i++)
    {
        if (T[i] != '#')
        {
            s2[++top2] = T[i];
        }
        else
        {
            if (top2 != -1)
                top2--;
        }
    }

    //比较栈
    if (top1 != top2)
        return false;
    
    for (i = 0; i < top1 + 1; i++)
    {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}
