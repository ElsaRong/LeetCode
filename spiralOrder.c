/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixColSize == NULL || 0 == matrixSize) {
        *returnSize = 0;
        return (int *)NULL;
    }

    int column = 0;
    int row = 0;

    int left = 0;
    int right = *matrixColSize - 1;
    int top = 0;
    int bottom = matrixSize - 1;
    
    int total = matrixSize * (*matrixColSize);
    int *order = (int *)malloc(sizeof(int)*total);
    *returnSize = 0;

    while (left <= right && top <= bottom) {
        for (column = left; column <= right; column++) {
            order[(*returnSize)++] = matrix[top][column];
        }
        for (row = top + 1; row <= bottom; row++) {
            order[(*returnSize)++] = matrix[row][right];
        }

        //上面2步骤可遍历一行或一列，如果大于等于2行且大于等于2列，再执行3、4步骤
        if (left < right && top < bottom) {
            for (column = right-1; column > left; column--) {
                order[(*returnSize)++] = matrix[bottom][column];
            }
            for (row = bottom; row > top; row--) {
                order[(*returnSize)++] = matrix[row][left];
            }
        }

        left++, right--, top++, bottom--;
    }
    return order;
}
