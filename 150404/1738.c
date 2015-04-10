/*
  大整数减法
  http://bailian.openjudge.cn/practice/2736/
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200
int subtraction(char a[], char b[], char c[], int max_len);

int main()
{
    int k;
    char ai[N+1] = {0}, bi[N+1] = {0};    //ai,bi是倒序输入的数字
    char a[N+1] = {0}, b[N+1] = {0}, c[N+1] = {0};      //a,b把倒序改成正序
    int a_len, b_len;

    //输入部分，注意是从高位往低位输入
    scanf("%s", bi);
    scanf("%s", ai);
    //计算数的长度
    a_len = strlen(ai);
    b_len = strlen(bi);

    //逆序改回顺序
    for (k=0; k<a_len; k++)  a[k] = ai[a_len-k-1] - '0';
    for (k=0; k<b_len; k++)  b[k] = bi[b_len-k-1] - '0';

    //计算部分，调用函数
    subtraction(a, b, c, b_len);

    //输出部分，从高位往低位输出
    while (c[k-1] == 0)  k--;
    while (k > 0) {
        printf("%d", c[k-1]);
        k--;
    }
    printf("\n");

    return 0;
}

int subtraction(char a[], char b[], char c[], int max_len) {
    int m, k;
    for (k=0; k<max_len; k++) {
        m = b[k] - a[k] - c[k];
        if (m < 0) {
            c[k] = m + 10;
            c[k+1] = 1;
        }
        else {
            c[k] = m;
        }
    }
    return 0;
}
