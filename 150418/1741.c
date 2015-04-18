/*
  http://bailian.openjudge.cn/practice/2739/
  2739:计算对数
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100

int main()
{
    int n, i, x, k;
    int a_len, b_len;
    char a[N+1]={0}, b[N+1]={0};
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%s%s", a, b);
        if (strcmp(a, b) == 0) printf("1\n");
        if (strcmp(a, b) > 0) printf("0\n");
        if (strcmp(a, b) < 0) {

            
        }
    }
    return 0;
}

/*
1.要计算幂
2.要比较大小，boj说写个类似strcmp的
3.要传递长度，传到函数里？？boj说不需要判断，每次按照最大N算