int maxSubArray(int* nums, int numsSize){
    int preMaxSum = nums[0]; //用于存储之前的最大值
    int sum = nums[0];       //用于存储上一次求和的结果
    int i = 0;

    for (i = 1; i < numsSize; i++) {
        sum = fmax(sum + nums[i], nums[i]);  //
        preMaxSum = fmax(preMaxSum, sum);
    }
    return preMaxSum;
}
