/*
  2692:假币问题
http://bailian.openjudge.cn/practice/2692
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char left[3][7], right[3][7], result[3][5];
bool isHeavy(char c); // 判断假币 x 是否为重的代码
bool isLight(char c); // 判断假币 x 是否为轻的代码

int main()
{
    int n, i, j;
    char c;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        for (j=0; j<3; j++) {
            scanf("%s%s%s", left[j], right[j], result[j]);
        }
        for (c='A'; c<='L'; c++) {
            if (isLight(c)) {
                printf("%c is the counterfeit coin and it is light.\n", c);
                break;
            }
            if (isHeavy(c)) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }
    }
    return 0;
}

bool isHeavy(char c) // 判断假币 x 是否为重的代码
{
    int i, j;
    // 判断是否与三次称量结果矛盾
    for (i=0; i<3; i++) {
        for (j=0; left[i][j] != '\0'; j++) {
            if (c == left[i][j]) {
                if (strcmp(result[i], "up") != 0) return false;
            }
        }
        for (j=0; right[i][j] != '\0'; j++) {
            if (c == right[i][j]) {
                if (strcmp(result[i], "down") != 0) return false;
            }
        }
    }
    return true;
}

bool isLight(char c) // 判断假币 x 是否为轻的代码
{
    int i, j;
    // 判断是否与三次称量结果矛盾
    for (i=0; i<3; i++) {
        for (j=0; left[i][j] != '\0'; j++) {
            if (c == left[i][j]) {
                if (strcmp(result[i], "down") != 0) return false;
            }
        }
        for (j=0; right[i][j] != '\0'; j++) {
            if (c == right[i][j]) {
                if (strcmp(result[i], "up") != 0) return false;
            }
        }
    }
    return true;
}
