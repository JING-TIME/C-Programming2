/*
  3:画家问题
  http://ustc.openjudge.cn/ex5/3/
  对应于熄灯问题：
  1.黄色对应熄灯状态0
  2.白色对应开灯状态1
  3.1表示按一次开关,0表示不需要操作
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define N1 20 // 测试案例数，最多20
#define N2 15 // 方阵的大小，最大15*15

void SwitchStatus(int k, int *pSwitch, int n);
void ApplySwitch(int *pLights, int *pNextLights, int *pSwitchs, int n);
int main()
{
    int i, j, k, m, min, opera;
    int t;                // 存案例数
    int n[N1];            // 每组方阵大小
    char c;
    int Origrid[N2+2][N2+2];    // 方阵初始状态
    int grid[N2+2][N2+2];       // 方阵的当前状态
    int Switch[N2+2][N2+2];     //　每个格子是否需要操作
    scanf("%d\n", &t);


    // 对于每组测试方阵
    for (i=0; i<t; i++) {
        scanf("%d\n", &n[i]);
        min=n[i]*n[i]+1;        // 存最小操作数(可能的最大操作是n*n),+1是为了最后判断是否被修改,没有的话就是无解
        for (j=1; j<=n[i]; j++) {
            for (k=1; k<=n[i]; k++) {
                scanf("%c", &c);
                if (c=='y')  Origrid[j][k] = 0;      // 黄色表示0，及熄灯
                if (c=='w')  Origrid[j][k] = 1;      // 白色表示1，及开灯
                // 注意,外围包了一圈多余的格子,因此边界不需要特殊处理啦
                scanf("\n"); // 分行
            }
        }



        // 遍历首行开关的64种状态
        for (m=pow(2, n[i])-1; m>=0; m--) {
            // 初始化操作数为0
            opera = 0;
            // 每次初始化当前状态
            memcpy(grid, Origrid, sizeof(grid));
            // 算出n所代表的开关状态，放到anSwitch[0]
            SwitchStatus(m, Switch[1], n[i]);

            // 下面逐行让开关起作用，并算出下一行开关应该是什么状态
            for (k=1; k<=n[i]; k++) {
                // 算出第k行开关起作用后的结果
                ApplySwitch(grid[k], grid[k+1], Switch[k], n[i]);
                // 第k+1行的开关状态应和第k行的灯状态一致,因为下一行操作就是为了把上一行灯关掉
                memcpy(Switch[k+1], grid[k], sizeof(grid[k]));
            }

            bool bOk = true; //记录最后一行灯是不是全灭
            // 看最后一行灯是不是全灭
            for (k=1; k<=n[i]; k++ ) {
                if (grid[n[i]][k]) {
                    bOk = false;
                    break;
                }
            }
            if (bOk) {
                for (k=1; k<=n[i]; k++) {
                    for (j=1; j<=n[i]; j++) {
                        if (Switch[k][j])  opera += 1;
                    }
                }
                if (opera < min) min = opera;
            }
        }
        if (min != n[i]*n[i]+1) printf("%d\n", min);
        else printf("inf\n");
    }
    return 0;
}

void SwitchStatus(int k, int *pSwitch, int n)
{
    int i;
    pSwitch[0] = 0;
    for(i=0; i<n; i++) {
        pSwitch[i+1] = (k>>i) & 1;
        // 因为pSwitch外围包一圈，所以要+1
    }
}

void ApplySwitch(int *pLights, int *pNextLights, int *pSwitchs, int n)
{
    int i;
    for (i=1; i<=n; i++) {
        if(pSwitchs[i]) {
            pLights[i-1] = 1 - pLights[i-1]; // 开关左边的灯改变状态
            pLights[i] = 1 - pLights[i]; // 开关所在位置的灯改变状态
            pLights[i+1] = 1 - pLights[i+1]; // 开关右边的灯改变状态
            pNextLights[i] = 1 - pNextLights[i]; // 开关下边的灯改变状态
        }
    }
}
