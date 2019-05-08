#include<stdio.h>                //spfa基本上要这些头文件
#include<string.h>
#include<queue>
#include<map>
using namespace std;

const int maxn=550;
const int maxm=5e5+5;
const int INF=0x3f3f3f3f;

int head[maxn],point[maxm<<1],nxt[maxm<<1],val[maxm<<1],size;
int dis[maxn],vis[maxn];
int flag[maxn][maxn];
int inq[maxn];
int J,L,W,m,M;

void init(){
	memset(inq,0,sizeof(inq));
	memset(flag,0,sizeof(flag));
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,int v){    //有向图只需要前一半
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

bool spfa(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	vis[s]=1;
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		if(inq[u]>J)return 0;
		q.pop();
		vis[u]=0;
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			if(dis[j]>dis[u]+val[i]){
				dis[j]=dis[u]+val[i];
				if(!vis[j]){
					q.push(j);
					inq[j]++;
					vis[j]=1;
				}
			}
		}
	}
	return 1;
}
int main(){
	while(scanf("%d%d%d%d%d",&J,&L,&W,&m,&M)!=EOF){
		if(J==0&&L==0&&W==0&&m==0&&M==0)break;
		init();
		bool f=0;
		while(L--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(flag[b][a]&1)f=1;
			else if(!(flag[a][b]&1)){
				add(a,b,M);
				add(b,a,-m);
				flag[a][b]&=1;
			}
		}
		while(W--){
			int a,b;
			scanf("%d%d",&a,&b);
			if((flag[a][b]&1)||(flag[b][a]&1))f=1;
			else if((!(flag[a][b]&2))&&(!(flag[b][a]&2))){
				add(a,b,0);
				add(b,a,0);
				flag[a][b]&=2;
				flag[b][a]&=2;
			}
		}
		if(f){
			printf("Impossible\n");
			continue;
		}
		for(int i=1;i<=J;++i){
			add(0,i,0);
		}
		f=spfa(0);
		if(!f)printf("Impossible\n");
		else{
			int maxx=-INF,minn=INF;
			for(int i=1;i<=J;++i){
				if(dis[i]<minn)minn=dis[i];
				if(dis[i]>maxx)maxx=dis[i];
			}
			printf("%d\n",maxx-minn);
		}
	}
	return 0;
}
