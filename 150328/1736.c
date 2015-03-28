/*
  http://ustc.openjudge.cn/assignment3/1/
  1:十进制到八进制
 */

#include <stdio.h>

int transfer(unsigned int num) {
    if (num<8) printf("%d", num%8);
    else {
        transfer(num/8);
        printf("%d", num%8);
    }
}

int main()
{
    unsigned int num;
    scanf("%d", &num);

    transfer(num);
    printf("\n");
    return 0;
}

/*
其他做法，print("%o", n);输出
或把每次除出来的东西放到 int a[7]数组里
 */

/*
  用不着考虑数据类型转换，也不用把累次输出的数保存到数组，直接输出即可。
  考虑一下用位运算怎么做
 */
