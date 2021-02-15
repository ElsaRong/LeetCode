 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** ret = NULL;
    int i = 0, j = 0;

    /* 返回二维数组大小（行大小）和列大小指针 */
    *returnSize = numRows;                             //行数
    *returnColumnSizes = malloc(sizeof(int)*numRows);  //每一列列数的数组

    ret = (int **)malloc(sizeof(int *)*numRows);
    for (i = 0; i < numRows; i++) {
        ret[i] = malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;                 //每列列数和当前行数正相关
        ret[i][0] = ret[i][i] = 1;
        for (j = 1; j < i; j++) {
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    return ret;
}
