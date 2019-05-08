#include <bits/stdc++.h>
using namespace std;

int m[105][105];

void print(int l,int r,int num){
	if(l>r)return;
	for(int i = l ; i <= r ; ++ i){
		for(int j = l ; j <= r ; ++ j){
			m[i][j] = num;
		}
	}
	print(l+1,r-1,num+1);
}

int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	int n;
	scanf("%d",&n);
	print(1,n,1);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= n ; ++ j){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
