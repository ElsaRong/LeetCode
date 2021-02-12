
typedef struct {
    int *arr;
    int arrSize;
    int k;
} KthLargest;

void swap(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
}
void maxHeap(int *arr, int p, int arrSize)
{
    int l, r = 0;
    //从左儿子开始，依次向下遍历
    for (l = 2*p+1; l < arrSize; l = 2*l+1)
    {
        if (l >= arrSize) break;
        r = l + 1;
        //找出左右儿子最大值
        if (r < arrSize && arr[r] < arr[l])
        {
            l = r;
        }
        //将左右儿子最大值和父节点交换
        if (arr[l] < arr[p])
        {
            swap(&arr[l], &arr[p]);
            p = l;
        }
        else
        {
            break; //以该l为起始的子树排序完成，跳出for循环
        }
    }
}

void printfArr(int *arr, int arrSize)
{
    int i = 0;
    for (i = 0; i < arrSize; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

void heapSort(int *arr, int arrSize)
{
    int i = 0;
    if (arrSize <= 1) return;
    //从第一个非叶子开始，比较父子大小，构造小顶堆
    for (i = arrSize/2 - 1; i >=0; i--)
    {
        maxHeap(arr, i, arrSize);
    }
    //从最后一个叶子开始，和首元素交换后，生成降序序列
    for (i = arrSize - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeap(arr, 0, i); //第三个入参，表示待调整的剩余heap大小
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    int i = 0;
    static KthLargest *kthLargest = NULL;
    kthLargest = malloc(sizeof(KthLargest));
    kthLargest->arr = malloc(sizeof(int) * 10^4); 
    memset(kthLargest->arr, 0, sizeof(int) * 10^4);
    for (i = 0; i < numsSize; i++)
    {
        kthLargest->arr[i] = nums[i];
    }
    //输入数据流经过堆排序，生成降序序列
    heapSort(kthLargest->arr, numsSize);
    printf("初始数组:");
    printfArr(kthLargest->arr, numsSize);
    kthLargest->arrSize = numsSize;
    kthLargest->k = k;
    return kthLargest;
}

/* 
 *  obj->arr是降序序列，新增一个元素时，先替换队尾元素再重新堆排序
 */
int kthLargestAdd(KthLargest* obj, int val) 
{
    //如果降序序列未满k，元素加入序列尾，排序
    if (obj->arrSize < obj->k)
    {
        obj->arr[obj->arrSize] = val; //降序序列大小为0
        obj->arrSize++;
    } 
    else
    {
        //降序序列满k，如果小于序列尾，直接return；否则替换队列尾
        if (obj->arr[obj->arrSize - 1] >= val)
        {
            printfArr(obj->arr, obj->arrSize);
            return obj->arr[obj->k - 1];
        }
        else
        {
            obj->arr[obj->arrSize - 1] = val;
        }
    }
    heapSort(obj->arr, obj->arrSize);
    printfArr(obj->arr, obj->arrSize);
    return obj->arr[obj->k - 1];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->arr);
    obj->arr = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
