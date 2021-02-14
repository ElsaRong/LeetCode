/* 
 * 动态规划在寻找[有很多重叠子问题的情况时的最优解]时有效
 */

#define MAX(a, b) (((a)>(b))?(a):(b))
int maxSubArray(int* nums, int numsSize){
    int sum, preMax, i = 0;
    sum = preMax = nums[0];
    for (i = 1; i < numsSize; i++) {
        sum = MAX(sum + nums[i], nums[i]);
        preMax = MAX(sum, preMax);      
    }
    return preMax;
}
