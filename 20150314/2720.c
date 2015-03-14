/*
http://ustc.openjudge.cn/ex1/2/
学生信息用qsort排序
全局题号 2720
 */

#include <stdio.h>
#include <string.h>    // strcasecmp()函数在这里
#include <stdlib.h>    // sqort()函数在这里

#define N 100  //学生不会超过100个


// 定义一个学生结构体
struct student {
    char name[19];
    int id;    // id <= 100,000
    char sex;  // 'M' or 'F'
    int age;   // age <= 100
};

int main()
{
    int i=0, j=0;
    char name[19];
    struct student stu[N];

    /******* 输入数据部分 *******/
    while(gets(stu[i].name) != NULL) {
        //当返回值是NULL时，输入完成
        if (strlen(stu[i].name) != 0) {
            //当输入行是空行时（长度是0），重新输入
            scanf("%d,%c %d", &stu[i].id, &stu[i].sex, &stu[i].age);
            i++;
        }
    }

    /*******　比较部分　*******/
    qsort(stu, i, sizeof(struct student), strcasecmp);

    /******* 输出部分　*******/
    for(j=0; j<i; j++) {
        printf("%s\n", stu[j].name);
        printf("%08d,%c %d\n", stu[j].id, stu[j].sex, stu[j].age);
    }
    return 0;
}



