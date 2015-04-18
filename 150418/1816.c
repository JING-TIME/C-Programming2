/*
  4:拨钟问题
http://ustc.openjudge.cn/ex5/4/
 */
#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, count=0, min=36;
    int c[10], oc[10];            // c-clock
    int o[10];   //用来记录9个移动的操作次数
    int min_o[10]={0,0,0,0,0,0,0,0,0};  //min_o最小操作

    for (i=1; i<=9; i++) scanf("%d", &oc[i]);
    memcpy(c, oc, sizeof(oc));

    for (o[1]=0; o[1]<4; o[1]+=1) {
        for (i=0; i<o[1]; i++)  { c[1]+=1; c[2]+=1; c[4]+=1; c[5]+=1; }
        for (o[2]=0; o[2]<4; o[2]+=1) {
            for (i=0; i<o[2]; i++)  { c[1]+=1; c[2]+=1; c[3]+=1; }
            for (o[3]=0; o[3]<4; o[3]+=1) {
                for (i=0; i<o[3]; i++)  { c[2]+=1; c[3]+=1; c[5]+=1; c[6]+=1; }
                for (o[4]=0; o[4]<4; o[4]+=1) {
                    for (i=0; i<o[4]; i++)  { c[1]+=1; c[4]+=1; c[7]+=1; }
                    for (o[5]=0; o[5]<4; o[5]+=1) {
                        for (i=0; i<o[5]; i++)  { c[2]+=1; c[4]+=1; c[5]+=1; c[6]+=1; c[8]+=1; }
                        for (o[6]=0; o[6]<4; o[6]+=1) {
                            for (i=0; i<o[6]; i++)  { c[3]+=1; c[6]+=1; c[9]+=1; }
                            for (o[7]=0; o[7]<4; o[7]+=1) {
                                for (i=0; i<o[7]; i++)  { c[4]+=1; c[5]+=1; c[7]+=1; c[8]+=1; }
                                for (o[8]=0; o[8]<4; o[8]+=1) {
                                    for (i=0; i<o[8]; i++)  { c[7]+=1; c[8]+=1; c[9]+=1; }
                                    for (o[9]=0; o[9]<4; o[9]+=1) {
                                        for (i=0; i<o[9]; i++)  { c[5]+=1; c[6]+=1; c[8]+=1; c[9]+=1; }

                                        if (c[1]%4==0 && c[2]%4==0 && c[3]%4==0 && c[4]%4==0 && c[5]%4==0
                                            && c[6]%4==0 && c[7]%4==0 && c[8]%4==0 && c[9]%4==0) {
                                            for (count=0, i=1; i<=9; i++) count += o[i];
                                            if (count < min) {
                                                min = count;
                                                for (i=1; i<=9; i++) min_o[i] = o[i];
                                            }
                                        }
                                        for (i=0; i<o[9]; i++)  { c[5]-=1; c[6]-=1; c[8]-=1; c[9]-=1; }
                                    }
                                    for (i=0; i<o[8]; i++)  { c[7]-=1; c[8]-=1; c[9]-=1; }
                                }
                                for (i=0; i<o[7]; i++)  { c[4]-=1; c[5]-=1; c[7]-=1; c[8]-=1; }
                            }
                            for (i=0; i<o[6]; i++)  { c[3]-=1; c[6]-=1; c[9]-=1; }
                        }
                        for (i=0; i<o[5]; i++)  { c[2]-=1; c[4]-=1; c[5]-=1; c[6]-=1; c[8]-=1; }
                    }
                    for (i=0; i<o[4]; i++)  { c[1]-=1; c[4]-=1; c[7]-=1; }
                }
                for (i=0; i<o[3]; i++)  { c[2]-=1; c[3]-=1; c[5]-=1; c[6]-=1; }
            }
            for (i=0; i<o[2]; i++)  { c[1]-=1; c[2]-=1; c[3]-=1; }
        }
        for (i=0; i<o[1]; i++)  { c[1]-=1; c[2]-=1; c[4]-=1; c[5]-=1; }
    }

    //输出部分
    for (i=1; i<=9; i++) {
        for (j=0; j<min_o[i]; j++) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
