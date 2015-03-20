/*
http://ustc.openjudge.cn/ex2/3/
3:特殊日历计算
闰年:四年一闰,百年不闰,四百年再闰.366天,平时365天.
 */

#include <stdio.h>

int MonToDays[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int LMonToDays[12] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

//判断是否是闰年
int isleap(int year)
{
    int leap;  //如果是闰年返回1,否则返回0
    if (year%400 == 0) leap = 1;
    else if (year%100 == 0) leap = 0;
    else if (year%4 == 0) leap = 1;
    else leap = 0;
    return leap;
}

//计算对应年份之前的所有天数(即算出之前年份中有几个闰年)
int year2day(int year)
{
    int leap, noleap;
    long int days;
    leap = (year-1997)/4 - (year-1901)/100 + (year-1601)/400;
    noleap = (year-2000) - leap;
    days = leap*366 + noleap*365;
    return days;
}

//计算从一天到上个月总天数
int mon2day(int month, int year) {
    int days;

    if (month == 1) days = 0;

    else if (isleap(year)) days = LMonToDays[month-2];
    else days = MonToDays[month-2];
    return days;
}

//常用日历法和特殊日历法的转换
int convert(int hour, int minute, int second, int day, int month, int year)
{
    int special_hour, special_minute, special_second, special_day, special_month, special_year;
    long int sum_days, sum_seconds;
    // 把当下时间分成天数和秒数两部分分别计算

    //计算出常用日历法从2000开始到现在的所有天数
    sum_days = year2day(year) + mon2day(month, year) + day;
    sum_seconds = (3600*hour + 60*minute + second)*1000; //*1000是化小数为整数,方便计算

    //转换成特殊日历法,天数部分
    special_year = (sum_days-1)/1000;
    special_month = ((sum_days-1) % 1000)/100 + 1;
    special_day = (sum_days-1) % 100 + 1;

    //秒数部分
    special_hour = sum_seconds/(8640*1000);
    special_minute = (sum_seconds % 8640000)/86400;
    special_second = (sum_seconds % 86400)/864;
    //输出
    printf("%d:%d:%d %d.%d.%d\n", special_hour, special_minute, special_second, special_day, special_month, special_year);
    return 0;
}

int main()
{
    int n, i;

    //输入部分;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        int h, min, s, d, mon, y;
        scanf("%d:%d:%d %d.%d.%d", &h, &min, &s, &d, &mon, &y);
        //输出部分在函数内
        convert(h, min, s, d, mon, y);
    }
    return 0;
}


/*
经验教训
1.尽量不要用小数计算,乘以一定倍数变成整数
2.注意输入数字范围,会不会超出数据类型的大小,如 int, long, long long
3.变量名不要太短,尽量还是能看懂,ss就不如special_second好.
4.提交了3次两次错误都是算法上面的
 */