#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int ma[105][105],id[105],n;

void init(){
	memset(ma,0,sizeof(ma));
	memset(id,0,sizeof(id));
}

void topo(){
	queue<int>q;
	for(int i=1;i<=n;++i)if(!id[i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		printf("%d",u);
		if(++cnt==n)printf("\n");
		else printf(" ");
		for(int i=1;i<=n;++i)if(ma[u][i]){
			id[i]--;
			if(!id[i])q.push(i);
		}
	}
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(!ma[a][b]){
				ma[a][b]=1;
				id[b]++;
			}
		}
		topo();
	}
	return 0;
}
