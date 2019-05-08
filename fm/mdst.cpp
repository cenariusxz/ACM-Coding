#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;
const int INF=0x3f3f3f3f;
//点数及边数

int from[maxm],to[maxm],cost[maxm],cntm;	//这些是用来存边的
int pre[maxn],id[maxn],vis[maxn],in[maxn];
//pre是当前图中某个点所选的入边编号；id是当前图中某个点的编号，同一圈内的编号相同；in是当前图中某个点所选的入边权值

void init(){
	cntm=0;
}

void add_mdst(int a,int b,int v){	//加边
	from[cntm]=a;
	to[cntm]=b;
	cost[cntm++]=v;
}

int mdst(int s,int n){
	int ans=0,u,v;
	while(1){
		memset(in,0x3f,sizeof(in));		//一开始先将所有点入边权赋为无穷大
		for(int i=0;i<cntm;++i){		//对于每一条边，如果它不在某个圈内，那么就用它来尝试更新点的入边
			if(from[i]!=to[i]&&cost[i]<in[to[i]]){
				pre[to[i]]=from[i];
				in[to[i]]=cost[i];
			}
		}
		for(int i=1;i<=n;++i){			//如果某个非根节点没有最小入边，则没有最小树形图，无解
			if(i!=s&&in[i]==INF){
				return -1;
			}
		}
		int cnt=0;						//圈的个数/缩完之后点的总数
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		in[s]=0;
		for(int i=1;i<=n;++i){
			ans+=in[i];
			v=i;
			while(vis[v]!=i&&id[v]==-1&&v!=s){	//将一条链/圈标上同一标记
				vis[v]=i;
				v=pre[v];
			}
			if(v!=s&&id[v]==-1){		//当当前访问的不是长链连到根并且是一个没有标记过的圈，则标记这个圈
				++cnt;
				for(u=pre[v];u!=v;u=pre[u])id[u]=cnt;
				id[v]=cnt;
			}
		}
		if(!cnt)break;					//无环，合并过程结束
		for(int i=1;i<=n;++i){			//将剩余点依次标序号
			if(id[i]==-1)id[i]=++cnt;
		}
		for(int i=0;i<cntm;){			//删去圈内的边；由于之前在遍历点的时候将入边权都加上了，所以在新图中将所有边权都减去原入边边权
			v=to[i];
			from[i]=id[from[i]];
			to[i]=id[to[i]];
			if(from[i]!=to[i])cost[i++]-=in[v];
			else{
				--cntm;
				cost[i]=cost[cntm];
				to[i]=to[cntm];
				from[i]=from[cntm];
			}
		}
		n=cnt;
		s=id[s];
	}
	return ans;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		add_mdst(a,b,v);
	}
	printf("%d\n",mdst(1,n));
	return 0;
}
