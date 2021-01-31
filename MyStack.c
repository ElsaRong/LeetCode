#define QSIZE 32

typedef struct queue{
    int *data; //数组指针
    int rear;  //队尾
    int front; //队首
    int size;  //数组大小（队列大小）
} Queue;

typedef struct {
    Queue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

Queue *initQueue(int size) {
    Queue *q = malloc(sizeof(Queue));
    q->data = malloc(sizeof(int) * size);
    q->rear = q->front = -1;
    q->size = size;
    return q;
}

int isEmpty(Queue *q) {
    //队首地址为-1，说明队列为空
    return q->front == -1;
}

void enQueue(Queue *q, int value) {
    if (-1 == q->front)
    {
        //队列为空，队首指针置0
        q->front = 0;
    }
    //队尾指针++（考虑队列满时循环覆盖）
    q->rear = (q->rear + 1)%(q->size);
    q->data[q->rear] = value;   
    return;         
}

int deQueue(Queue *q) {
    //要出队的队首元素
    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        //队列中仅一个元素，出队后置空
        q->front = -1;
        q->rear = -1;
        return value;
    }
    //出队后队首指针++
    q->front = (q->front + 1) % q->size;
    return value;
}

MyStack* myStackCreate() {
    MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
    myStack->q1 = initQueue(QSIZE);
    myStack->q2 = initQueue(QSIZE);
    return myStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (isEmpty(obj->q1))
    {
        //如果q1为空，先入队q2
        enQueue(obj->q2, x);
    }
    else
    {
        //如果q1不为空，先入队q1
        enQueue(obj->q1, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (isEmpty(obj->q1))
    {
        //如果q1为空q2不为空，依次出列q2到q1直到q2中有且仅有一位
        while(obj->q2->front != obj->q2->rear)
            enQueue(obj->q1, deQueue(obj->q2));
        return deQueue(obj->q2);
    }
    //如果q1不为空，依次出列q1到q2直到q1中有且仅有一位
     while(obj->q1->front != obj->q1->rear)
        enQueue(obj->q2, deQueue(obj->q1));
    return deQueue(obj->q1);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (isEmpty(obj->q1))
        return obj->q2->data[obj->q2->rear];
    else
        return obj->q1->data[obj->q1->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->q1->front == -1) && (obj->q2->front == -1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    obj->q1->data = NULL;
    free(obj->q1);
    obj->q1 = NULL;

    free(obj->q2->data);
    obj->q2->data = NULL;
    free(obj->q2);
    obj->q2 = NULL;

    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
