#include <bits/stdc++.h>
using namespace std;

int n,r;
int a[25];

void print(){
    for(int i = 1 ; i <= r ; ++ i){
        printf("%d",a[i]);
        if(i == r)printf("\n");
        else printf(" ");
    }
}

void dfs(int t){
    if(t == r){
        print();
        return;
    }
    for(int i = a[t]+1 ; i <= n ; ++ i){
        a[t+1] = i;
        dfs(t+1);
	}
}

int main(){
    scanf("%d%d",&n,&r);
    dfs(0);
    return 0;
}

