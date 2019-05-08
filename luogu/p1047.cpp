#include <bits/stdc++.h>
using namespace std;

int vis[10005];

int main(){
	int l,m;
	while(scanf("%d%d",&l,&m)!=EOF){
		memset(vis,0,sizeof(vis));
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			for(int i = a ; i <= b ; ++ i)vis[i]=1;
		}
		int ans = 0;
		for(int i = 0 ; i <= l ; ++ i){
			if(!vis[i])ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
