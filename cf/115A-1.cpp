#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

int ans,n;
int fa[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&fa[i]);
	for(int i = 1 ; i <= n ; ++ i){
		int cnt = 0;
		int now = i;
		while(now != -1){
			cnt++;
			now = fa[now];
		}
		if(cnt > ans)ans = cnt;
	}
	printf("%d\n",ans);
	return 0;
}
