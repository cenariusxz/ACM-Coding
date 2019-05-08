#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int add[maxn][maxn],del[maxn][maxn];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int i = x1 ; i <= x2 ; ++ i){
			add[i][y1]++;del[i][y2]--;
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		int tmp = 0;
		for(int j = 1 ; j <= n ; ++ j){
			tmp += add[i][j];
			printf("%d",tmp);
			if(j == n)printf("\n");
			else printf(" ");
			tmp += del[i][j];
		}
	}
	return 0;
}
