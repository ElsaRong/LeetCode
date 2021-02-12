struct HASH_DATA {
    int numVal;
    int index;
    struct HASH_DATA *next;
};

struct HASH_TABLE {
    struct HASH_DATA **head;
    int tableSize;
};

//散列函数，返回所在表中的下标
int hashAddr(struct HASH_TABLE *table, int numVal) {
    int index = abs(numVal)%table->tableSize;
    return index;
}

//初始化哈希表，默认哈希bucket大小100
void hashInit(struct HASH_TABLE *table, int tableSize) {
    table->head = (struct HASH_DATA **)malloc(sizeof(struct HASH_DATA *) * tableSize);
    //如果不初始化bucket数组的值，值不为空时会解引用指针到可能崩溃的内存
    memset(table->head, 0, sizeof(struct HASH_DATA *) * 100); 
    table->tableSize = tableSize;
}

//如果新增numVal经过散列所得哈希表下标超出表大小，表新增
void hashInsert(struct HASH_TABLE *table, int numVal, int index) {
    int p = 0;
    struct HASH_DATA *data;

    p = hashAddr(table, numVal);
    data = (struct HASH_DATA *)malloc(sizeof(struct HASH_DATA));
    data->numVal = numVal;
    data->index = index;
    data->next = NULL;
    table->head[p] = data;
    return;
}

struct HASH_DATA *hashFind(struct HASH_TABLE *table, int numVal) {
    int p = 0;
    struct HASH_DATA *listHead;
    p = hashAddr(table, numVal); //该值应该在哈希表中的地址or索引
    if (p >= table->tableSize)
    {
        return NULL; //超过哈希表范围
    }
    else
    {
        listHead = table->head[p];
        while (NULL != listHead) //哈希表该地址处，data结构体指针不为空（暨有data结点）
        {
            if (listHead->numVal == numVal) //查找该键值对应的链表中，和目标numVal一致的
                return listHead;
            listHead = listHead->next;
        }
    }
    return NULL;
}

void hashFree(struct HASH_TABLE *table)
{
    int i = 0; 
    struct HASH_DATA *listHead = NULL;
    struct HASH_DATA *tmp = NULL;

    if (NULL == table->head)
        return;

    for (i = 0; i < table->tableSize; i++)
    {
        listHead = table->head[i];
        while (NULL != listHead)
        {
            tmp = listHead;
            listHead = listHead->next;
            free(tmp);
        }
    }
    table->tableSize = 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i , diff = 0;
    int *res;
    struct HASH_DATA *data = NULL;
    struct HASH_TABLE table;

    res = malloc(sizeof(int) * 2);
    *returnSize = 0;

    hashInit(&table, 100);
    for (i = 0; i < numsSize; i++)
    {
        diff = target - nums[i];
        //如果哈希表中存在该值，返回该哈希表中记录的index和当前的i
        data = hashFind(&table, diff);
        if (NULL != data)
        {
            res[0] = data->index;
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        //如果不存在，哈希表新增元素
        hashInsert(&table, nums[i], i);
    }
    hashFree(&table);
    return res;
}
