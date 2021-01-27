t#define MAXSIZE 1024*1024

typedef struct {
    int top;              //栈顶
    int *initStack;       //原始栈
    int *auxiliaryStack;  //辅助栈
    int min;              //最小值
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    static MinStack *minStack = NULL;
    minStack = malloc(sizeof(MinStack));
    if (NULL == minStack)
    {
        return NULL;
    }

    minStack->top = -1;
    minStack->initStack = (int *)malloc(sizeof(int)*MAXSIZE);
    minStack->auxiliaryStack = (int *)malloc(sizeof(int)*MAXSIZE);
    if (NULL == minStack->initStack || NULL == minStack->auxiliaryStack)
    {
        return NULL;
    }

    memset(minStack->initStack, 0, sizeof(sizeof(int)*MAXSIZE));
    memset(minStack->auxiliaryStack, 0, sizeof(sizeof(int)*MAXSIZE));

    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    //原始栈先Push
    obj->top++;
    obj->initStack[obj->top] = x;

    //辅助栈再Push：栈为空，直接入栈；栈不为空，比较栈顶
    if (obj->top == 0)
    {
        obj->auxiliaryStack[obj->top] = x;
    }
    else 
    {
        if (obj->auxiliaryStack[obj->top - 1] < x)
        {
            obj->auxiliaryStack[obj->top] = obj->auxiliaryStack[obj->top - 1];
        }
        else
        {
            obj->auxiliaryStack[obj->top] = x;
        }
    }
    
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->initStack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->auxiliaryStack[obj->top];
}

void minStackFree(MinStack* obj) {
    if (NULL != obj->initStack)
    {
        free(obj->initStack);
        obj->initStack = NULL;
    }

    if (NULL != obj->auxiliaryStack)
    {
        free(obj->auxiliaryStack);
        obj->auxiliaryStack = NULL;
    }

    if (NULL != obj)
    {
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
