int fib(int n){
    int ret, i = 0;
    int *dp = NULL;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    dp = (int *)malloc(sizeof(int) * (n+1)); //注意：数组内存要多分配一位
    dp[0] = 0, dp[1] = 1;                    //注意：n>=2的情况需要重新初始化数组1、2号元素
    for (i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1000000007;
    }
    return dp[n];    
}
