/*
  2:垂直直方图
  http://ustc.openjudge.cn/ex2/2/
  全局题号1802
 */

#include <stdio.h>

int main()
{
    // ASCII A-65, Z-90;
    int j, i=0, max=0;
    int a[26] = {0};
    char c;


    //输入部分
    while (i < 4) {
        scanf("%c", &c);
        if (c >= 65 && c <= 90) {
            a[c-65] += 1;
            if (a[c-65] > max) max = a[c-65];
        }
        if (c == '\n') i++;
    }

    //输出部分
    for (j=0; j<max; j++) {
        for (i=0; i<26; i++) {
            if (a[i] >= max-j) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
    for (i=0; i<26; i++) {
        printf("%c ", 65+i);
    }
    printf("\n");

    return 0;
}
