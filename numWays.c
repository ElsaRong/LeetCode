int numWays(int n){
    int *dp, i = 0;
    dp = (int *)malloc(sizeof(int)*(n+1));

    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        dp[1] = 1, dp[2] = 2;
        for (i = 3; i <= n; i++) {     //注意：数组大小是n+1，下标边界为n
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= 1000000007;       
        }
        return dp[n];                   //注意：返回值为dp数组第n个元素
    }
}
