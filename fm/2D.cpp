#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=1e4+5;
const int maxm=2e4+5;

int ans,n;
int id[maxn],num[maxn];
int head[maxn],point[maxm],nxt[maxm],size;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

bool topo(){
	ans=0;
	queue<int>q;
	for(int i=1;i<=n;++i)if(!id[i]){
		q.push(i);
		num[i]=888;
	}
	int cnt=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		ans+=num[u];
		cnt++;
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			id[j]--;
			if(!id[j]){
				num[j]=num[u]+1;
				q.push(j);
			}
		}
	}
	if(cnt==n)return 1;
	return 0;
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(head,-1,sizeof(head));
		size=0;
		memset(id,0,sizeof(id));
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(b,a);
		}
		if(topo())printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
