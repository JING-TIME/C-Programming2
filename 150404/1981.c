/*
2980:大整数乘法
http://bailian.openjudge.cn/practice/2980/
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200
int multiplication(char a[], char b[], char result[], int a_len, int b_len, int r_len);

int main()
{
    int k;
    char ai[N+1] = {0}, bi[N+1] = {0};    //ai,bi是倒序输入的数字
    char a[N+1] = {0}, b[N+1] = {0}, result[2*N+1] = {0};      //a,b把倒序改成正序
    int a_len, b_len, r_len;

    //输入部分，注意是从高位往低位输入
    scanf("%s", ai);
    scanf("%s", bi);

    //如果输入有0,直接输出0
    if (ai[0]=='0' || bi[0]=='0') {
        printf("0\n");
        return 0;
    }

    //计算数的长度
    a_len = strlen(ai);
    b_len = strlen(bi);
    r_len = a_len + b_len;
    //逆序改回顺序
    for (k=0; k<a_len; k++)  a[k] = ai[a_len-k-1] - '0';
    for (k=0; k<b_len; k++)  b[k] = bi[b_len-k-1] - '0';



    //计算部分，调用函数
    multiplication(a, b, result, a_len, b_len, r_len);



    //输出部分，从高位往低位输出
    while (result[r_len-1] == 0)  r_len--;
    while (r_len > 0) {
        printf("%d", result[r_len-1]);
        r_len--;
    }
    printf("\n");

    return 0;
}

int multiplication(char a[], char b[], char result[], int a_len, int b_len, int r_len) {
    int m, i, j;

    for (i=0; i<b_len; i++) {
        for (j=0; j<a_len; j++) {
            m = b[i]*a[j] + result[i+j];
            result[i+j] = m % 10;
            result[i+j+1] += m / 10;
        }
    }
    return 0;
}
