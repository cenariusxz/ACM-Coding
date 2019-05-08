#include<stdio.h>
#include<string.h>
const int INF=0x3f3f3f3f;

int head[1005],dist[1005],next[4005],point[4005],val[4005];
bool vis[1005];
int size;

void add(int a,int b,int v){
	int i;
	for(i=head[a];~i;i=next[i]){
		if(point[i]==b){
			if(val[i]>v){
				val[i]=v;
			}
			return;
		}
	}
	point[size]=b;
	val[size]=v;
	next[size]=head[a];
	head[a]=size++;
}

int main(){
	int t,n;
	while(scanf("%d%d",&t,&n)!=EOF){
		int i,j;
		size=0;
		memset(head,-1,sizeof(head));
		for(i=1;i<=t;i++){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++){
			dist[i]=INF;
		}
		for(i=head[n];~i;i=next[i]){
			dist[point[i]]=val[i];
		}
		int t=n;
		dist[n]=0;
		vis[n]=1;
		for(i=1;i<n;i++){
			int m=INF;
			for(j=1;j<=n;j++){
				if(!vis[j]&&dist[j]<m){
					t=j;
					m=dist[j];
				}
			}
			vis[t]=1;
			for(j=head[t];~j;j=next[j]){
				if(!vis[point[j]]&&(dist[point[j]]>m+val[j])){
					dist[point[j]]=m+val[j];
				}
			}
		}
		printf("%d\n",dist[1]);
	}
	return 0;
}
