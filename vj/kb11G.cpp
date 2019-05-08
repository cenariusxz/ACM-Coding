#pragma comment(linker,"/STACK:16777216")
#include<stdio.h>
#include<string.h>
const int maxm=100100;
const int maxv=200100;
const int INF=0x3f3f3f3f;

int s,t;
int n,m;
int d[maxm],cur[maxm];
bool vis[maxm];
int head[maxm],point[maxv],flow[maxv],nxt[maxv],size;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
}

void add(int a,int b,int c){
	point[size]=b;
	flow[size]=c;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	flow[size]=c;
	nxt[size]=head[b];
	head[b]=size++;
}

bool bfs(){
	memset(vis,0,sizeof(vis));
	int q[maxm],cnt=0;
	q[++cnt]=s;
	vis[s]=1;
	d[s]=0;
	for(int i=1;i<=cnt;i++){
		int u=q[i];
		for(int j=head[u];~j;j=nxt[j]){
			if(!vis[point[j]]&&flow[j]>0){
				d[point[j]]=d[u]+1;
				q[++cnt]=point[j];
				vis[point[j]]=1;
			}
		}
	}
	return vis[t];
}

int dfs(int x,int a){
	if(x==t||a==0)return a;
	int ans=0,f;
	for(int i=head[x];~i;i=nxt[i]){
		if(d[point[i]]==d[x]+1&&flow[i]>0){
			f=dfs(point[i],a<flow[i]?a:flow[i]);
			flow[i]-=f;
			flow[i^1]+=f;
			ans+=f;
			a-=f;
			if(a==0)break;
		}
	}
	if(ans==0)d[x]=-1;
	return ans;
}

int mf(){
	int ans=0;
	while(bfs()){
		ans+=dfs(s,INF);
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){

		init();
		scanf("%d%d",&n,&m);
		int i,j,minx,maxx;
		for(i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(i==1){
				minx=x;
				maxx=x;
				s=t=i;
			}
			else{
				if(x>maxx){
					maxx=x;
					s=i;
				}
				else if(x<minx){
					minx=x;
					t=i;
				}
			}
		}
		for(i=1;i<=m;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		printf("%d\n",mf());
	}
	return 0;
}
