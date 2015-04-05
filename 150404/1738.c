/*
  ASCII 0~48, 9~57
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200
int subtraction(char a[], char b[], char c[], int max_len);

int main()
{
    int k, m;
    char ai[N] = {0}, bi[N] = {0};    //ai,bi是倒序输入的数字
    char *pa = ai, *pb = bi;
    char a[N] = {0}, b[N] = {0}, c[N+1] = {0};      //a,b把倒序改成正序
    int a_len, b_len, max_len;

    //输入部分，注意是从高位往低位输入
    scanf("%s", ai);
    scanf("%s", bi);

    //排除前导0
    while (*pa=='0' && *(pa+1)!='\0')  pa++;
    while (*pb=='0' && *(pb+1)!='\0')  pb++;
    a_len = strlen(pa);
    b_len = strlen(pb);

    //逆序改回顺序
    for (k=0; k<a_len; k++)  a[k] = *(pa+a_len-k-1) - 48;
    for (k=0; k<b_len; k++)  b[k] = *(pb+b_len-k-1) - 48;

    //计算部分，调用函数
    subtraction(a, b, c, max_len);

    //输出部分，从高位往低位输出
    if (c[k] != 0)  printf("%d", c[k]);
    while (k > 0) {
        printf("%d", c[k-1]);
        k--;
    }
    printf("\n");

    return 0;
}

int subtraction(char a[], char b[], int max_len) {
    int k;
    for (k=0; k<max_len; k++) {
        m = a[k] + b[k] + sum[k];
        if (m >= 10) {
            sum[k] = m - 10;
            sum[k+1] = 1;
        }
        else {
            sum[k] = m;
        }
    }
}
