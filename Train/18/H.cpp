#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
struct node{
	int to,next;
};
vector<node> edge;
int head[MAXN<<1];
int a,b,n;
int t[MAXN],d[MAXN];
int match[MAXN<<1],vis[MAXN];

void addedge(int x,int y)
{
	node tmp;
	tmp.to=y;
	tmp.next=head[x];
	head[x]=edge.size();
	edge.push_back(tmp);
}

int dfs(int s)
{
	for(int i=head[s];~i;i=edge[i].next){
		int j=edge[i].to;
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||dfs(match[j])){
				match[j]=s;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i,j,ans=0;
	memset(head,-1,sizeof(head));
	memset(match,-1,sizeof(match));
	scanf("%d%d%d",&a,&b,&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&t[i],&d[i]);
	for(i=1;i<=n;i++){
		if(d[i]) continue;
		for(j=i+1;j<=n;j++){
			if(d[j]==0) continue;
			if(t[j]-t[i]>b&&t[j]-t[i]<a) continue;
			addedge(i,j);
			addedge(j,i);
		}
	}
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)==1){
			ans++;
		}
	}
	if(ans==n){
		printf("No reason\n");
		for(i=1;i<n;i++){
			if(d[i]) continue;
			printf("%d %d\n",t[i],t[match[i]]);
		}
	}
	else{
		printf("Liar\n");
	}
		
 return 0;
}
