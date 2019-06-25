#include <bits/stdc++.h>
using namespace std;

int a[20],used[20],used_fu[20],used_zhu[20];
int sum = 0;

void print(){
    for(int i = 1 ; i <= 8 ; ++ i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void dfs(int k){        //已放完前k行
    if(k == 8){
        print();
        sum++;
        return;
    }
    // 填k+1行
    for(int i = 1 ; i <= 8 ; ++ i){
        if(used[i])continue;
        if(used_fu[ i + k+1 ])continue;
        if(used_zhu[ i - (k+1) + 7])continue;
        a[k+1] = i;
        bool flag = true;       //表示第 k+1行可以填i
        if(flag == true){
            used[i] = 1 ;
            used_fu[ i + k+1 ] = 1;
            used_zhu[ i - (k+1) + 7] = 1;
            dfs(k+1);
            used[i] = 0;
            used_fu[ i + k+1 ] = 0;
            used_zhu[ i - (k+1) + 7] = 0;
        }
    }
}

int main(){
    dfs(0);
    printf("%d\n",sum);
    return 0;
}
