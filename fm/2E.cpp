#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxm=105;

int id[maxm],n;
int head[maxm],point[maxm],nxt[maxm],size;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

bool topo(){
	queue<int>q;
	for(int i=0;i<n;++i)if(!id[i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		cnt++;
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			id[j]--;
			if(!id[j])q.push(j);
		}
	}
	if(cnt==n)return 1;
	return 0;
}

int main(){
	int m;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&m);
		memset(id,0,sizeof(id));
		memset(head,-1,sizeof(head));
		size=0;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		if(topo())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
