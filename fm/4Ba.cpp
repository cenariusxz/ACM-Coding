#include<stdio.h>
#include<string.h>

const int maxn=1e4+1;
const int maxm=2e4+1;
const int maxq=2e6+1;

int n;
int head[maxn],nxt[maxm],point[maxm],val[maxm],size;
int fa[maxn],dis[maxn];
int vis[maxn];
int ans[1000001];
int head1[maxn],point1[maxq],nxt1[maxq],size1;

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	val[size]=v;
	nxt[size]=head[b];
	head[b]=size++;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
/*
void Tarjan(int s,int pre){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j!=pre){
			dis[j]=dis[s]+val[i];
			Tarjan(j,s);
			int x=find(j),y=find(s);
			if(x!=y)fa[x]=y;
		}
	}
	vis1[s]=cnt;
	for(int i=head1[s];~i;i=nxt1[i]){
		int j=point1[i];
		if(vis[j]==vis1[s]){
			int lca=find(j);
			int id=i/2;
			ans[id]=dis[s]+dis[j]-2*dis[lca];
		}
	}
}
*/
void tarjan(int s)
{
    int i;
    vis[s]=true;
    fa[s]=s;
    for(i=head[s];i!=-1;i=nxt[i])
    {
        if(!vis[point[i]])
        {
            dis[point[i]]=dis[s]+val[i];
            tarjan(point[i]);
			fa[point[i]]=s;
        }
    }
    for(i=head1[s];i!=-1;i=nxt1[i])
    {
        if(vis[point1[i]])
        {
            if(dis[point1[i]]!=-1)
            {
                ans[i/2]=dis[s]+dis[point1[i]]-2*dis[find(point1[i])];
            }
            else ans[i/2]=-1;
        }
    }
}

int main(){
	int m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		memset(head,-1,sizeof(head));
		size=size1=0;
		memset(head1,-1,sizeof(head1));
		memset(ans,-1,sizeof(ans));
		cnt=0;
		for(int i=0;i<m;++i){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		for(int i=0;i<k;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			point1[size1]=b;
			nxt1[size1]=head1[a];
			head1[a]=size1++;
			point1[size]=a;
			nxt1[size1]=head1[b];
			head1[b]=size1++;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				memset(dis,-1,sizeof(dis));
				dis[i]=0;
				tarjan(i);
			}
		}
		for(int i=0;i<k;++i){
			if(ans[i]==-1)printf("Not connected\n");
			else printf("%d\n",ans[i]);
		}
	}
	return 0;
}
