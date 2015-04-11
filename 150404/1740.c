/*
未完，代码不对
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int i, n;
    double a, b;
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%lf", &a);
        scanf("%lf", &b);
        printf("%.20lf\n", a+b);
    }
    return 0;
}
