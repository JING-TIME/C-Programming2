/*
  1:两倍
  http://ustc.openjudge.cn/ex2/1/
  全局题号1809
 */

#include <stdio.h>
#define N 16

int ndouble(int a[], int n) {
    int i, j, num=0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (a[j] == 2*a[i]) {
                num ++;
                break;
            }
        }
    }
    return num;
}

int main()
{
    int n, i=0;
    int a[N];

    //输入部分
    scanf("%d", &n);
    while (n != -1) {
        a[i] = n;
        i++;
        scanf("%d", &n);

        if (n == 0) {
            printf("%d\n", ndouble(a, i));
            i = 0;
            scanf("%d", &n);
        }
    }
    return 0;
}
