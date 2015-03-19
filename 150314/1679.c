/*
http://ustc.openjudge.cn/ex1/3/
全局题号 1679
*/

#include <stdio.h>

#define N 100

int main()
{
    int a[N+2][N+2];
    int n, i, j, area=0, border=0;
    scanf("%d", &n);

    //读入矩阵数据
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    //在读入矩阵外围包上一圈保护层，防止越界
    for (i=0; i<=n+1; i++) {
        a[i][0] = 99;  //左边界
        a[i][n+1] = 99;  //右边界
    }
    for (j=0; j<=n+1; j++) {
        a[0][j] = 99;  //上边界
        a[n+1][j] = 99;  //下边界
    }

    //判断是否是肿瘤，是否是肿瘤边界
    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if (a[i][j] <= 50) {
                area += 1;  //肿瘤数加１
                if (a[i-1][j]>50 ||
                    a[i+1][j]>50 ||
                    a[i][j-1]>50 ||
                    a[i][j+1]>50 ) {
                    border += 1;  //边界数加１
                }
            }
        }
    }

    printf("%d %d\n", area, border);
    return 0;
}
