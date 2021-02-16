int minCostClimbingStairs(int* cost, int costSize){
    int *dp = NULL;
    int i = 0;

    dp = malloc(sizeof(int) * (costSize+1)); 
    dp[0] = dp[1] = 0;
    for (i = 2; i <= costSize; i++) {
        dp[i] = fmin(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]); //画图可得，cost体现在i的下一个元素
    }
    return dp[costSize]; //注意返回的dp元素下标
}
