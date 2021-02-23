
#include <string.h>

char * addStrings(char * num1, char * num2){
    int num1Len = strlen(num1);
    int num2Len = strlen(num2);
    int i = num1Len - 1;
    int j = num2Len - 1;
    int sumLen = fmax(num1Len, num2Len) + 2;  //和的字符串length，+1用于进位，+1用于字符串结束符
    int flag = 0; //是否进位

    int x = 0, y = 0, sum = 0, p = 0;
    int tmp = 0;

    char *ret = (char *)malloc(sizeof(char) * sumLen);
    memset(ret, 0, sizeof(char) * sumLen);

    while (i >=0 || j >= 0 || flag > 0) {
        x = i>=0?num1[i]-'0':0;
        y = j>=0?num2[j]-'0':0;
        sum = x + y + flag;
        ret[p++] = sum%10 + '0';
        flag = sum/10;
        i--, j--;
    }

    for (i = 0; 2*i < p-1; i++) {
        tmp = ret[i];
        ret[i] = ret[p-1-i];
        ret[p-1-i] = tmp;
    }

    return ret;
}
