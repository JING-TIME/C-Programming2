/*
4:谁拿了最多奖学金
http://ustc.openjudge.cn/ex1/4/
*/

#include <stdio.h>

//定义学生结构体
struct student {
    char name[20];
    int score1;  // 0~100
    int score2;  // 0~100
    char isleader;  // Y or N
    char iswest;  // Y or N
    int paper;   // 0~10
    int scholarship;
};
int handle_scholarship(struct student astu);


int main()
{
    int n, i, sum=0, winner;
    int max_money = 0;
    //输入部分
    scanf("%d", &n);
    struct student stu[n];
    for(i=0; i<n; i++) {
        scanf("%s %d %d %c %c %d", stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].isleader, &stu[i].iswest, &stu[i].paper);
    }

    //将学生按照奖学金多少排序
    for(i=0; i<n; i++) {
        stu[i].scholarship = handle_scholarship(stu[i]);
        sum += stu[i].scholarship;  //所有奖学金求和
        if (stu[i].scholarship > max_money) {
            winner = i;
            max_money = stu[i].scholarship;
        }
    }

    //输出部分
    printf("%s\n", stu[winner].name);
    printf("%d\n%d\n", stu[winner].scholarship, sum);
    return 0;
}

//计算奖学金函数
int handle_scholarship(struct student astu)
{
    int scholarship=0;
    if (astu.score1>80 && astu.paper>=1) scholarship += 8000;
    if (astu.score1>85 && astu.score2>80) scholarship += 4000;
    if (astu.score1>90) scholarship += 2000;
    if (astu.score1>85 && astu.iswest=='Y') scholarship += 1000;
    if (astu.score2>80 && astu.isleader=='Y') scholarship += 850;
    return scholarship;
}