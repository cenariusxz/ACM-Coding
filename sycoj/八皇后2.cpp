#include <bits/stdc++.h>
using namespace std;

int xx[8] = {1,-1,0,0,1,1,-1,-1};
int yy[8] = {0,0,1,-1,1,-1,1,-1};

int a[20][20];
int sum = 0;

void print(){
    for(int i = 1 ; i <= 8 ;++ i){
        for(int j = 1 ; j <= 8 ;++ j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void dfs(int k){        //已放完前k行
    if(k == 8){
        print();
        sum++;
        return;
    }
    // 填k+1行
    for(int i = 1 ; i <= 8 ; ++ i){     //判断a[k+1][i] 是否能放皇后
        bool flag = true;
        for(int j = 0 ; j < 8 ; ++ j){      //遍历八个方向
            // (k+1,i)
            int dx = k+1,dy = i;
            while(1){
                dx += xx[j];dy += yy[j];
                if(dx < 1 || dx > 8 || dy < 1 || dy > 8)break;      //出界，该方向没有皇后
                if(a[dx][dy] == 1)flag = false;                             //有皇后，不能放
            }
        }
        if(flag == true){
            a[k+1][i] = 1;
            dfs(k+1);
            a[k+1][i] = 0;
        }
    }
}

int main(){
    dfs(0);
    printf("%d\n",sum);
    return 0;
}
