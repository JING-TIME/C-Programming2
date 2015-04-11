/*
1:计算2的N次方
http://ustc.openjudge.cn/ex4/1/
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100

int multiplication(char a[], char b[], char result[], unsigned a_len, unsigned b_len);
int main()
{
    int i;
    unsigned n, a_len, b_len, r_len;
    unsigned long an, bn, resultn;
    char a[N+1]={0}, b[N+1]={0}, result[N+1]={0};

    //input part
    scanf("%u", &n);

    //calculate
    if (n < 64) {
        resultn = pow(2, n);
        printf("%lu\n", resultn);
        return 0;
    }
    else {
        an = pow(2, 63);
        bn = pow(2, n-63);
        a_len = 63*log10(2) + 1;
        b_len = (n-63)*log10(2) + 1;
        r_len = a_len + b_len;
        for (i=0; i<a_len; i++) {
            a[i] = an%10;
            an /= 10;
        }
        for (i=0; i<b_len; i++) {
            b[i] = bn%10;
            bn /= 10;
        }
    }

    multiplication(a, b, result, a_len, b_len);

    //output
    for (i=0; i<r_len; i++) {
        printf("%d", result[r_len-i-1]);
    }
    printf("\n");
    return 0;
}

int multiplication(char a[], char b[], char result[], unsigned a_len, unsigned b_len) {
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