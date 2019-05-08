#include <bits/stdc++.h>
using namespace std;

// 方向数组
int xx[3] = {1,-1,0};
int yy[3] = {0,0,1};

int used[105][105];         //某个格子有没有走过


int dfs(int k,int x,int y){     //已经走了k步，还要走完剩下步数的走法种类数
    if(k == 20)return 1;        //走满20步了，所以只有一种情况
    int sum = 0;
    for(int i = 0 ; i < 3 ; ++ i){
        int dx = x + xx[i];
        int dy = y + yy[i];
        //dx,dy 是从 x,y 向 i 方向上走一个之后的位置
        //普通题目中一般此处应该先判断是否出界，不过本题并不需要
        if(used[dx][dy])continue;           //如果这个格子走过了，那么就不能再走一遍
        used[dx][dy] = 1;                   //决定下一步走这个格子
        sum += dfs(k+1,dx,dy);          //走第k+1步，继续搜索
        if(sum > 1000000000)printf("No\n");
        used[dx][dy] = 0;                   //回溯，清除走过的标记
    }
    return sum;                         //返回得到的步数
}

int main(){
    used[50][50] = 1;
    printf("%d\n",dfs(0,50,50));
    return 0;
}
