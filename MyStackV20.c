#define MAX_SIZE 100

typedef struct {
    int *s1;
    int top1;
    int *s2;
    int top2;
    int size; //队列大小
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *myQueue = (MyQueue *)malloc(sizeof(MyQueue));
    myQueue->s1 = (int *)malloc(sizeof(int) * MAX_SIZE);
    myQueue->top1 = -1;
    myQueue->s2 = (int *)malloc(sizeof(int) * MAX_SIZE);
    myQueue->top2 = -1;
    myQueue->size = MAX_SIZE;
    return myQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    while(obj->top2 != -1)
    {
        obj->s1[++(obj->top1)] = obj->s2[obj->top2--];
    }
    obj->s1[++(obj->top1)] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    //s2为空，s1依次出栈到s2，直到s1最后一位
    if(obj->top2 == -1)
    {
        while(obj->top1 != 0)
        {
            obj->s2[++(obj->top2)] = obj->s1[obj->top1--];
        }
        obj->top1--;
        return obj->s1[0];
    }
    else
    {
        //s2不为空，弹出s2栈顶元素
        int x = obj->s2[obj->top2--];
        return x;
    }
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) 
{
    if (obj->top1 != -1)
    {
        return obj->s1[0];
    }
    else
    {
        return obj->s2[obj->top2];
    }
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if ((obj->top1 == -1) && (obj->top2 == -1))
        return true;
    else    
        return false;
} 

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    obj->s1 = NULL;
    free(obj->s2);
    obj->s2 = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
