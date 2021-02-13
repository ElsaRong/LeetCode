int findRepeatNumber(int* nums, int numsSize){
    int *mark = NULL;
    int i = 0;

    mark = (int *)malloc(sizeof(int) * numsSize);
    memset(mark, 0, sizeof(int) * numsSize);

    for (i = 0; i < numsSize; i++) {
        if (mark[nums[i]] == 0)
            mark[nums[i]]++;
        else
            return nums[i];
    }
    return -1;
}
