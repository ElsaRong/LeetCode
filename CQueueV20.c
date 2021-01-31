#define MAX_SIZE 20000

typedef struct {
    int *initStack;
    int *assistStack;
    int top;
    int minValue;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *minStack = (MinStack *)malloc(sizeof(MinStack));
    minStack->initStack = (int *)malloc(sizeof(int) * MAX_SIZE);
    minStack->assistStack = (int *)malloc(sizeof(int) * MAX_SIZE);
    minStack->top = -1;
    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top == -1)
    {
        ++obj->top;
        obj->initStack[obj->top] = obj->assistStack[obj->top] = x;
    }
    else
    {
        if (obj->assistStack[obj->top] < x)
        {
            int tmp = obj->assistStack[obj->top];
            ++obj->top;
            obj->initStack[obj->top] = x;
            obj->assistStack[obj->top] = tmp;
        }
        else
        {
            ++obj->top;
            obj->initStack[obj->top] = obj->assistStack[obj->top] = x;
        }     
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->initStack[obj->top];
}

int minStackMin(MinStack* obj) {
    return obj->assistStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->initStack);
    obj->initStack = NULL;
    free(obj->assistStack);
    obj->assistStack = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/
