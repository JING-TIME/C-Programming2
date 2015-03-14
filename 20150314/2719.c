/*位操作练习，全局题号2719
http://ustc.openjudge.cn/ex1/1/
代码主要分为两部分，输入部分和判断部分
 */
#include <stdio.h>
int judge(unsigned int a, unsigned int b);


int main()
{
    int i, n;
    unsigned int a, b;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        if (judge(a, b)) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}


int judge(unsigned int a, unsigned int b)
{
    int i;
    unsigned int x, y;
    for (i=0; i<16; i++) {
        if (a==b) {
            return 1;
        }
        else {
            x = a>>15;
            y = (1<<16)-1;
            a = ((a<<1)&y)|x;
        }
    }
    return 0;
}