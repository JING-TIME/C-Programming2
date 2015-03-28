/*
1799
http://ustc.openjudge.cn/assignment3/2/
2:最短前缀
 */

#include <stdio.h>
#include <string.h>   //strcmp
#include <stdlib.h>   //qsort

#define N 1000
#define L 20

struct dict {
    char word[L+1];
    char prefix[L+1];
    int index;
};

int find_prefix(struct dict my_dict[], int n)
{
    //通过把每个单词与它前后的两个单词对比，一一找出前缀
    int q, i, j, l;
    for (q=0; q<n; q++) {
        i=0;
        j=0;
        //除去边界条件
        if (q > 0) {
            while (my_dict[q-1].word[i] == my_dict[q].word[i])  i++;
        }
        if (q < n-1) {
            while (my_dict[q].word[j] == my_dict[q+1].word[j]) j++;
        }

        if (i < j) l = j;
        else l = i;

        my_dict[q].prefix[l+1] = '\0';
    }

}

int main()
{
    int i=0, j=0, n;
    struct dict my_dict[N];

    //输入部分
    while(scanf("%s", my_dict[i].word) != -1) {
        my_dict[i].index = i;
        strcpy(my_dict[i].prefix, my_dict[i].word);
        //先把prefix赋成完整的单词，再删除后部分
        i++;
    }
    n = i;

    //按照单词字母顺序排序
    qsort(my_dict, n, sizeof(struct dict), strcmp);

    //处理前缀
    find_prefix(my_dict, n);

    //按照输入顺序输出
    for (j=0; j<n; j++) {
        for (i=0; i<n; i++) {
            if (my_dict[i].index == j) {
                printf("%s %s\n", my_dict[i].word, my_dict[i].prefix);
                break;
            }
        }
    }
    return 0;
}

/* EOF
gets 返回 NULL
scanf 返回 -1

2,粗心错误
 */