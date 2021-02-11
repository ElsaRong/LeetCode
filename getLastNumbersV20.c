/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//p代表开始调整的父节点，调整方式是依次比较父子，步长是2p+1
void buildHeap(int *arr, int parent, int arrSize)
{
    int leftchild, rightchild = 0;
    int tmp = arr[parent]; //取出父节点值
    //从p的左儿子开始，依次向下遍历左儿子
    for (leftchild = 2*parent + 1; leftchild < arrSize; leftchild = 2*leftchild + 1)
    {
        //p的左儿子超出数组范围，返回
        if (leftchild >= arrSize) break;
        //选出p的儿子节点中最大值，和p比较
        rightchild = leftchild + 1; 
        if ((rightchild < arrSize) && (arr[rightchild] > arr[leftchild]))
        {
            leftchild = rightchild;
        }
        //交换p节点和子节点最大值，如果p的俩儿子都小于它，跳出本次循环；否则交换
        if (arr[leftchild] > arr[parent])
        {
            swap(&arr[parent], &arr[leftchild]);
            parent = leftchild;
        }
        else
        {
            break;
        }
    }
}

/* 堆排序思想：如果是无序序列输出升序序列，先构建大顶堆，此时整个序列的最大值在堆顶。
 * 将堆顶和堆末尾元素交换，则数组末尾为最大值，再将剩余n-1个元素重新构造大顶堆，
 * 获得倒数第二大值，依次循环 
*/
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i = 0;

    //初始化大顶堆，从最后一个非叶子节点开始，调整父子（i代表非叶子节点递减的调整顺序）
    for (i = arrSize/2 - 1; i >= 0; i--)
    {
        buildHeap(arr, i, arrSize);
    }

    //构建升序序列，从最后一个元素开始交换，交换完毕初始化大顶堆（0代表从堆顶开始的调整顺序）
    for (i = arrSize - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        buildHeap(arr, 0, i);
    }

    *returnSize = k;
    return arr;
}
