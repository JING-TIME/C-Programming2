/*
http://ustc.openjudge.cn/assignment3/3/
3:词典
 */

#include <stdio.h>
#include <string.h>

#define N 100000
#define L 10

struct dict {
    char foreign[L+1];
    char english[L+1];
};

int binary_search(char a[], struct dict my_dict[], int high) {
    int low=0;
    int temp=(low+high)/2;
    while (strcmp(a, my_dict[temp].foreign) != 0) {
        if (strcmp(a, my_dict[temp].foreign) > 0) low = temp;
        else high = temp;
        temp = (low + high)/2;
        if (high-low == 1) {
            if (strcmp(a, my_dict[low].foreign) == 0) return low;
            if (strcmp(a, my_dict[high].foreign) == 0) return high;
            else return -1;
        }
    }
    return temp;
}

int main()
{
    int i=0, j=0, k, n;
    char line[N][2L+3], trans[N][L+1];
    struct dict my_dict[N];

    gets(line[i]);
    //输入部分
    while (strlen(line[i]) != 0) {
        //空行不能用 ='\n' 来判断,用长度为0判断
        sscanf(line[i], "%s %s", my_dict[i].english, my_dict[i].foreign);
        i++;
        gets(line[i]);
    }
    //最后输入 i 行

    while (scanf("%s", trans[j]) != -1) {
        j++;
    }

    qsort(my_dict, i, sizeof(struct dict), strcmp);
    for (k=0; k<j; k++) {
        n = binary_search(trans[k], my_dict, i-1);
        if (n == -1) printf("eh\n");
        else printf("%s\n", my_dict[n].english);
    }
    return 0;
}


/*
  三个花时间的地方：
1.每次输入部分都要花我好多时间
2.每次二分法的边界条件都要花好多时间
3.两个对应数组的排序关系也弄不清
 */
