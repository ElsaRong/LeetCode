static bool isCupple(char *a, char *b)
{
    if ((*a == '(') && (*b == ')'))
    {
        return 0;        
    }   
    else if ((*a == '[') && (*b == ']'))
    {
        return 0;
    }
    else if ((*a == '{') && (*b == '}'))
    {
        return 0;        
    }
    else
    {
        return -1;
    }
}


bool isValid(char * s){
    char stack[10^4/2+1] = {0};
    char *stackTop = stack - 1;
    char *p = s;
    while (!p)
    {
        if ( *p == '(' || *p == '[' || *p == '{')
        {
            stackTop++;
            *stackTop = *p;
        }
        else
        {
            if (true == isCupple(stackTop, p))
            {
                stackTop--;
                if (stackTop == stack - 1)
                {
                    return 0;
                }
            }
            return -1;
        }
        p++;
    }
    return 0;
}
