//因为nums1和nums2已经有序，使用后序遍历
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1;
    int j = n - 1;
    int p = nums1Size - 1;
    while (i >= 0 && j >=0)
    {
        if (nums1[i] >= nums2[j]) {
            nums1[p] = nums1[i];
            p--, i--;
        } else {
            nums1[p] = nums2[j];
            p--, j--;
        }
    }

    while (i >= 0 && j < 0) {
        nums1[p] = nums1[i];
        i--, p--;
    }

    while (j >= 0 && i < 0 ) {
        nums1[p] = nums2[j];
        j--, p--;
    }
    return;
}
