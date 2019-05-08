#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int id[205],ma[205][205],n,ans[205],ans1[205];

bool topo(){
	priority_queue<int>q;
	for(int i=1;i<=n;++i)if(!id[i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.top();
		q.pop();
		ans[++cnt]=u;
		for(int i=1;i<=n;++i){
			if(i!=u&&ma[u][i]){
				id[i]--;
				if(!id[i])q.push(i);
			}
		}
	}
	if(cnt==n)return 1;
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m;
		scanf("%d%d",&n,&m);
		memset(ma,0,sizeof(ma));
		memset(id,0,sizeof(id));
		bool f=1;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a==b)f=0;
			else if(!ma[b][a]){
				ma[b][a]=1;
				id[a]++;
			}
		}
		if(!f)printf("-1\n");
		else{
			if(!topo())printf("-1\n");
			else{
				for(int i=1;i<=n;++i){
					ans1[ans[i]]=n-i+1;
				}
				for(int i=1;i<=n;++i){
					printf("%d",ans1[i]);
					if(i==n)printf("\n");
					else printf(" ");
				}
			}
		}
	}
	return 0;
}
