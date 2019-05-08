#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;

int num[maxn];
int n,m;

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
		for(int i = 1 ; i <= m ; ++ i)next_permutation(num+1,num+n+1);
		for(int i = 1 ; i <= n ; ++ i){
			printf("%d",num[i]);
			if(i == n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
