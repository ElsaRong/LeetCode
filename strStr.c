int strStr(char * haystack, char * needle){
    if(!haystack || !needle)
        return -1;

    if(!strlen(needle))
        return 0;
    
    int str1Len = strlen(haystack);
    int str2Len = strlen(needle);

    if(str1Len < str2Len)
        return -1;

    int i = 0, tmp1 = 0, tmp2 = 0;

    for(i = 0; i < str1Len; i++) {
        tmp1 = i;
        tmp2 = 0;

        if(str1Len - i < str2Len)
            return -1;
        printf("haystack = %c\n", haystack[tmp1]);
        printf("needle = %c\n", needle[tmp2]);
        while(haystack[tmp1++] == needle[tmp2++]) {
            if(tmp2 == str2Len) {
                return i;
            }
        }
    }
    return -1;
}
