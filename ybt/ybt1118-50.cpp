#include <bits/stdc++.h>
using namespace std;

int m[1005][1005];

int main(){
	memset(m,-1,sizeof(m));
	int n;
	scanf("%d",&n);
	for(int t = 1 ; t <= n ; ++ t){
		int a,b,g,k;
		scanf("%d%d%d%d",&a,&b,&g,&k);
		for(int i = 0 ; i < g ; ++ i){
			for(int j = 0 ; j < k ; ++ j){
				m[a+i][b+j] = t;
			}
		}
	}
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",m[x][y]);
	return 0;
}
