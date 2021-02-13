int singleNumber(int* nums, int numsSize){
    int i = 0;
    int x = 0;
    for (i = 0; i < numsSize; i++) {
        x ^= nums[i];
    }
    return x;
}
