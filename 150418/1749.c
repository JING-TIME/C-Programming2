/*
  2:数字方格
  http://ustc.openjudge.cn/ex5/2/
算法有待改进
 */

#include <stdio.h>

#define N 65535

int find_max(int n);

int main()
{
    int i, t, a[N];
    scanf("%d", &t);

    for (i=0; i<t; i++) {
        scanf("%d", &a[i]);
        printf("%d\n", find_max(a[i]));
    }
    return 0;
}

int find_max(int n)
{
    int max=0, a, b, c;
    for (a=0; a<=n; a++) {
        for (b=0; b<=n; b++) {
            for (c=0; c<=n; c++) {
                if ((a+b)%2==0 && (b+c)%3==0 && (a+b+c)%5==0) {
                    if (a+b+c > max) {
                        max = a+b+c;
                    }
                }
            }
        }
    }
    return max;
}
