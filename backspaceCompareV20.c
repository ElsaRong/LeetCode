#define MAX(a,b) (((a)>(b))?(a):(b))

bool backspaceCompare(char * S, char * T){
    int skipS = 0, skipT = 0;
    char *pS = NULL;
    char *pT = NULL;
    int i = strlen(S) - 1;
    int j = strlen(T) - 1;

    while (i >= 0 || j >= 0) {
        //第一个循环，用于取出S中待比较字符
        while (i >= 0) {
            if (S[i] == '#') {
                skipS++, i--;        
            } else if (skipS > 0) {
                i--, skipS--;  
            } else {
                break;
            }
        }
        //第二个循环，用于取出T中待比较字符
        while (j >= 0) {
            if (T[j] == '#') {
                skipT++, j--;
            } else if (skipT > 0) {
                j--, skipT--;
            } else {
                break;
            }
        }
        //两个字符串都未遍历完，比较大小后继续
        if (i >= 0 && j >= 0) {
            if (S[i] != T[j])  return false;
        } else {
            if (i >= 0 || j >= 0) return false;
        }
        i--, j--;
    }
    return true;
}
