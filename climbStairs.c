//动态规划，内存优化
int climbStairs(int n){
    int k = 3, ret = 0, a, b;
    if (1 == n) {
        return 1;
    } else if (2 == n) {
        return 2;
    } else {
        a = 1, b = 2;
        while (k <= n) {
            ret = a + b;  //注意：这里a,b,sum的关系很容易错
            a = b;        //b交替给a，sum交替给b，b淘汰
            b = ret;
            k++;
        } 
        return ret;
    }
}
