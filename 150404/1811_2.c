/* 用直接相乘的方法，计算m(1~9)的n次方 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 17000

int power(char a[], unsigned m, int len);
int main()
{
    int i;
    unsigned n, m;
    scanf("%u", &m);
    scanf("%d", &n);


    //用字符串保存数字
    //a表示结果
    char a[N] = {0};
    int len = n*log10(m)+1;    //计算a数组的长度
    a[0] = 1;


    //计算部分，每次乘m，高精度乘法
    for (i=0; i<n; i++) {
        power(a, m, len);
    }


    //输出部分
    for (i=0; i<len; i++) {
        printf("%d", a[len-i-1]);
    }
    printf("\n");
    return 0;
}

int power(char a[], unsigned m, int len) {
    int i, current;
    char b[N] = {0};  //b用来存储计算过程

    for (i=0; i<len; i++) {
            current = a[i]*m + b[i];
            a[i] = current % 10;
            b[i+1] = current / 10;
        }
    a[i] = b[i];

    return 0;
}