/*
百练：http://bailian.openjudge.cn/practice/2981/
大整数加法
ASCII 0~48, 9~57
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200

int main()
{
    int k, m;
    char ai[N] = {0}, bi[N] = {0};    //ai,bi是倒序输入的数字
    char *pa = ai, *pb = bi;
    char a[N] = {0}, b[N] = {0};      //a,b把倒序改成正序
    char sum[N+1] = {0};
    int a_len, b_len;

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

    //计算部分，从低位往高位计算
    for (k=0; k<a_len || k<b_len; k++) {
        m = a[k] + b[k] + sum[k];
        if (m >= 10) {
            sum[k] = m - 10;
            sum[k+1] = 1;
        }
        else {
            sum[k] = m;
        }
    }

    //输出部分，从高位往低位输出
    if (sum[k] != 0)  printf("%d", sum[k]);
    while (k > 0) {
        printf("%d", sum[k-1]);
        k--;
    }
    printf("\n");

    return 0;
}


/**********
 1.输入部分永远是最麻烦的!!!
 2.ASCII码和表达式的值有些混乱了...
***********/
