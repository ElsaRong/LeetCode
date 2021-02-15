class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int preMaxProfit = 0;
        int minPrice = 1e9;  //注意：C++中表示int的正无穷大表示

        //可以从第2天开始遍历，求前i天的最大利润
        //也可以从第1天开始遍历，需调整初始值，初始最低价为正无穷大，初始利润为0
        for (auto& val : prices) {
            preMaxProfit = max(preMaxProfit, val - minPrice);
            minPrice = min(minPrice, val);
        }
        return preMaxProfit;
    }
};
