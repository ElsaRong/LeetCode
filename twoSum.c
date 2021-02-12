/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j = 0;
    int *returnArr = NULL;
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (target == (nums[i] + nums[j]))
            {
                *returnSize = 2;
                returnArr = (int *)malloc(sizeof(int) * 2);
                returnArr[0] = i;
                returnArr[1] = j;
                return returnArr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
