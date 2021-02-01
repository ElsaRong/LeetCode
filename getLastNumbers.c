/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int comp(void *x, void *y)
 {
     return *(int *)x - *(int *)y;
 }

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i = -1;
    qsort(arr, arrSize, sizeof(int), comp);
    int *output = (int *)malloc(sizeof(int) * k);
    for (i = 0; i < k; i++)
    {
        output[i] = arr[i];
    }
    *returnSize = k;
    return output;
}
