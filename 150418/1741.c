/*
http://bailian.openjudge.cn/practice/2739/
2739:计算对数
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100

int multiple();
int intcmp();

int main()
{
    int n, i, x;
    int a_len, b_len, r_len;
    char a[N+1]={0}, b[N+1]={0}, result[2N+3];
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%s%s", a, b);
        if (strcmp(a, b) == 0) printf("1\n");
        if (strcmp(a, b) > 0) printf("0\n");
        if (strcmp(a, b) < 0) {

            /* 接下来进行大整数乘法 */
            // 计算a的长度
            a_len = strlen(a);
            // 调整字符串顺序
            for (k=0; k<a_len; k++)  a[k] = ai[a_len-k-1] - '0';


            // 每次把结果乘以 a
            for (x=0; x<20; x++) {
                power = ;
                if (intcmp(result, b) > 0) {
                    printf("%d", x-2);
                    break;
                }

            }
        }
    }
    return 0;
}


int multiple(char a[], char result[], int a_len) {
    int i, j, temp;

    for (i=0; i<N+1; i++) {
        for(j=0; j<a_len; j++) {
            temp = result[i]*a[j] + result[i+1];
            result[i+j] = temp % 10;
            result[i+j+1] += temp / 10;
        }
    }

    return 0;
}

int intcmp()