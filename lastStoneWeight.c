/*
 * 思路：生成升序序列，取最后两个元素粉碎（先求差、再delete）
 * 新序列重新生成升序序列，依次循环
*/
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void maxHeap(int *arr, int p, int arrSize)
{
    int l, r = 0;
    //儿子和父节点比较，交换；依次向下
    for (l = 2*p+1; l < arrSize; l = 2*l + 1)
    {
        if (l >= arrSize) break;
        //如果存在右儿子，找到儿子中最大
        r = l + 1;
        if (r < arrSize && arr[r] > arr[l])
        {
            l = r;
        }
        //如果儿子比父大，交换；否则break本次循环
        if (arr[l] > arr[p])
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

void heapSort(int* stones, int stonesSize)
{
    int i = 0;
    //先生成大顶堆
    for (i = stonesSize/2 - 1; i >= 0; i--) //【waring】第一个非叶子的下标
    {
        maxHeap(stones, i, stonesSize);
    }
    //再生成升序序列
    for (i = stonesSize - 1; i > 0; i--)
    {
        swap(&stones[0], &stones[i]);
        maxHeap(stones, 0, i);  //【warning】对除最后一个元素执行堆排序，param 3表示数组大小
    }
}

int lastStoneWeight(int* stones, int stonesSize){
    int i = 0;
    heapSort(stones, stonesSize);

    //取最后两个元素粉碎
    for (i = stonesSize - 1; i > 0; i--)
    {
        //相等，直接删除两个元素继续比较
        if (stones[i] == stones[i-1]) 
        {
            stonesSize-=2;
            i--;
            if (stonesSize == 1) break;
            else continue;
        }
        //不等，倒数第二个元素重新赋值，stones序列重新堆排序
        if (stones[i] != stones[i-1])
        {
            stones[i-1] = abs(stones[i] - stones[i-1]);
            stonesSize-=1;
            if (stonesSize == 1) break; 
            else heapSort(stones, stonesSize);
        }
    }
    if (stonesSize == 1)
    {
        return stones[0];
    }
    else
    {
        return 0;
    }
}
