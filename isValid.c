static bool isCupple(char *top, char *c)
{
    switch (*top)
    {
        case '(':
            if (')' == *c) return true;
            break;
        case '[':
            if (']' == *c) return true;
            break;
        case '{':
            if ('}' == *c) return true;
            break;
    }
    return false;
}


bool isValid(char * s)
{
    int i = 0;
    int top = -1;
    int strLen = -1;
    char *stack = NULL;

    strLen = strlen(s);
    stack = malloc(strLen);
    if (!stack)
    {
        printf("malloc failed\n");
        return false;
    }

    for (i = 0; i < strLen; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            //左符号，入栈
            stack[++top] = s[i];
        }
        else
        {
            //右符号和栈顶括号成对，出栈
            if (0 <= top && true == isCupple(stack + top, s + i))
            {
                top--;
            }
            else 
            {
                //栈已空，遇到右符号，返回false；不成对，返回false
                free(stack);
                return false;
            }
        }
    }
    
    free (stack);
    //字符串已比较完，栈为空，说明有效
    if (top == -1)
        return true;
    else
        return false;
}
