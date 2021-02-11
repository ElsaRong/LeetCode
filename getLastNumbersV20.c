/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void heapSort(int *arr, int p, int arrSize)
{
    int l, r = 0;

    //从p的左儿子开始，依次向下遍历左儿子
    for (l = 2*p + 1; l < arrSize; l = 2*l + 1)
    {
        if (l >= arrSize)
        {
            break; //左儿子超出数组范围，返回
        }
        
        //选出子节点中最小值，和父节点比较
        r = l + 1; 
        if ((r < arrSize) && (arr[r] < arr[l]))
        {
            l = r;
        }
        //交换父节点和子节点最小值，如果已成堆，返回
        if (arr[l] < arr[p])
        {
            swap(&arr[l], &arr[p]);
            p = l;
        }
        else
        {
            break;
        }

    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i = 0;
    int *output = NULL;
    //初始化最小堆（从最后一个非叶子节点开始总右至左、从下至上调整，满足父节点<子节点）
    for (i = arrSize/2 - 1; i >= 0; i--)
    {
        heapSort(arr, i, arrSize);
    }

    //生成有序队列（从最后一个叶子节点开始，和堆顶元素交换后，重新调整堆）
    for (i = arrSize - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapSort(arr, 0, i);
    }
    output = (int *)malloc(sizeof(int) * (k + 1));
    memset(output, 0, k+1);
    for (i = 0; i < k; i++)
    {
        output[i] = arr[i];
    }
    *returnSize = k;
    return output;
}
