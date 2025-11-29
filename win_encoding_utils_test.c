#include "win_encoding_utils.h"
#include <stdio.h>
#include <stdlib.h>

/*
    gcc win_encoding_utils_test.c win_encoding_utils.c
*/
int main(void) {
    int len;
    char* str = weu_utf8_to_ascii("这是我的测试代码", &len);
    printf("%d, %s\n", len, str);
    free(str);
    return 0;
}
