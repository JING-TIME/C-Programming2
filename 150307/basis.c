// bitwise operation
// 最简单的位运算

#include<stdio.h>

int main()
{
    printf("%d\n", 6&11) ;  // 按位与
    printf("%d\n", 21|18);  // 按位或
    printf("%d\n", 21^18);  // 按位异或
    printf("%d, %u, %x\n", ~21, ~21, ~21);  // 按位非
    printf("%d\n", 9<<4);  // 左移运算符

    unsigned char c = 15;
    printf("c=%d\n", c);

    c <<= 6;
    printf("c=%d, c=%x\n", c, c);
    printf("%d\n", c<<4);

    
    return 0;
}

