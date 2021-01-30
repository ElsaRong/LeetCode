#define MAX_SIZE 10000

typedef struct {
    int *QHeadStack;
    int qHead;
    int *QTailStack;
    int qTail;
} CQueue;


CQueue* cQueueCreate() {
    static CQueue cQueue;
    memset(&cQueue, 0, sizeof(CQueue));
    cQueue.QHeadStack = malloc(sizeof(int) * MAX_SIZE);
    cQueue.QTailStack = malloc(sizeof(int) * MAX_SIZE);
    cQueue.qHead = -1;
    cQueue.qTail = -1;
    return &cQueue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    int i = -1;
    //空队列，直接入栈
    if (obj->qHead == -1 && obj->qTail == -1)
    {
        obj->QHeadStack[++obj->qHead] = value;
    } 
    else if (obj->qHead == -1 && obj->qTail >= 0)
    {
        //上一次执行了队列头部元素删除，先重建再插入
        while (obj->qTail >= 0)
        {
            obj->QHeadStack[++i] = obj->QTailStack[obj->qTail--];
        }
        obj->QHeadStack[++i] = value;
    }
    else
    {
        obj->QHeadStack[++obj->qHead] = value;
    }
}

int cQueueDeleteHead(CQueue* obj) {
    int i = -1;
    //空队列，返回失败
    if (obj->qHead == -1 && obj->qTail == -1)
    {
        return -1;
    }
    else if (obj->qHead >= 0 && obj->qTail == -1)
    {
        //上一次执行了队列尾部添加，HeadStack除栈底元素，逐个迁移到TailStack
        while(obj->qHead > 0)
        {
            obj->QTailStack[++obj->qTail] = obj->QHeadStack[obj->qHead--];
        }
        obj->qHead--;
        return obj->QHeadStack[0];
    }
    else if (obj->qHead == -1 && obj->qTail >= 0)
    {
        i = obj->qTail--;
        return obj->QTailStack[i];
    }
    else
    {
        i = obj->qTail--;
        return obj->QTailStack[i];
    }
}

void cQueueFree(CQueue* obj) {
    if (!obj)
    {
        return;
    }

    if (obj->QHeadStack)
        free(obj->QHeadStack);
    obj->qHead = -1;
    if (obj->QTailStack)
        free(obj->QTailStack);
    obj->qTail = -1;
    return;
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
