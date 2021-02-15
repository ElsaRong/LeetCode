#define MAX_PROFIT(a, b) (((a)>(b))?(a):(b))
#define MIN_PRICE(a, b)  (((a)<(b))?(a):(b))

int maxProfit(int* prices, int pricesSize){
    int *dp;
    int minPrice = prices[0]; //初始值，第一天为最低价
    int maxProfit = 0;        //初始值，第一天卖出时，最大利润为0（暨无利润）
    int i = 1;

    dp = (int *)malloc(sizeof(int) * pricesSize);
    dp[0] = 0;
    for (i = 1; i < pricesSize; i++) {
        dp[i] = MAX_PROFIT(dp[i-1], prices[i]-minPrice);     //前i天的最大利润
        minPrice = MIN_PRICE(minPrice, prices[i]);           //前i天的最低价
    }
    return dp[i-1]; //注意：当i不满足循环跳出时，i==6已经越界
}
