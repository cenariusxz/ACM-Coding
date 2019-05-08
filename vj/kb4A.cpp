#include<stdio.h>
#include<string.h>
#define min(a,b) a<b?a:b

int next[4005],head[1005],point[4005],val[4005],size,dist[1005];
bool vis[1005];

void add(int a,int b,int v){
	for(int i=head[a];~i;i=next[i]){
		if(point[i]==b){
			if(val[i]>v)val[i]=v;
			return;
		}
	}
	val[size]=v;
	point[size]=b;
	next[size]=head[a];
	head[a]=size++;
}

int main(){
	int t,n;
	while(scanf("%d%d",&t,&n)!=EOF){
		int a,b,v,i;
		size=0;
		memset(head,-1,sizeof(head));
		memset(next,0,sizeof(next));
		memset(point,0,sizeof(point));
		for(i=1;i<=t;i++){
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		memset(vis,0,sizeof(vis));
		memset(dist,-1,sizeof(dist));
		vis[1]=1;
		int t=1,j;
		for(i=head[1];~i;i=next[i]){
			dist[point[i]]=val[i];
		}
		dist[1]=0;
		for(i=1;i<=n;i++){
			int m=0x3f3f3f3f;
			for(j=1;j<=n;j++){
				if(!vis[j]&&~dist[j]&&dist[j]<m){
					m=dist[j];
					t=j;
				}
			}
			vis[t]=1;
			for(j=head[t];~j;j=next[j]){
				if(!vis[point[j]]&&(dist[point[j]]==-1||dist[point[j]]>dist[t]+val[j])){
					dist[point[j]]=dist[t]+val[j];
				}
			}
		}
		printf("%d\n",dist[n]);
		for(i=1;i<=n;i++){
			printf("%d:",i);
			for(j=head[i];~j;j=next[j]){
				printf("->%d %d",point[j],val[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
