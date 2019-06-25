#include <bits/stdc++.h>
using namespace std;

int a[50],used[50],used_fu[50],used_zhu[50];
int sum = 0;
int n;

void print(){
    for(int i = 1 ; i <= n ; ++ i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void dfs(int k){        //已放完前k行
	if(k == n){
    	sum++;
		if(sum <= 3)print();
        return;
    }
    // 填k+1行
    for(int i = 1 ; i <= n ; ++ i){
        if(used[i])continue;
        if(used_fu[ i + k+1 ])continue;
        if(used_zhu[ i - (k+1) + n-1])continue;
        a[k+1] = i;
        bool flag = true;       //表示第 k+1行可以填i
        if(flag == true){
            used[i] = 1 ;
            used_fu[ i + k+1 ] = 1;
            used_zhu[ i - (k+1) + n-1] = 1;
            dfs(k+1);
            used[i] = 0;
            used_fu[ i + k+1 ] = 0;
            used_zhu[ i - (k+1) + n-1] = 0;
        }
    }
}

int main(){
	scanf("%d",&n);
    dfs(0);
    printf("%d\n",sum);
    return 0;
}
