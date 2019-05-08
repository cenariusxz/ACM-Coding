#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;
const int maxm=4e5+5;

int head[2][maxn],point[2][maxm],nxt[2][maxm],size[2];
int aim[maxn];
int is[maxn];
bool vis[maxn],del[maxn];

void init(){
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(del,0,sizeof(del));
	memset(is,0,sizeof(is));
	size[0]=size[1]=0;
}

void add(int a,int b,int c=0){
	point[c][size[c]]=b;
	nxt[c][size[c]]=head[c][a];
	head[c][a]=size[c]++;
	point[c][size[c]]=a;
	nxt[c][size[c]]=head[c][b];
	head[c][b]=size[c]++;
}

bool dfs(int s){
	vis[s]=1;
	bool f=0;
	if(is[s])f=1;
	for(int i=head[0][s];~i;i=nxt[0][i]){
		int j=point[0][i];
		if(vis[j])continue;
		if(dfs(j))f=1;
	}
	if(!f){
		del[s]=1;
	}
	return f;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(int i=1;i<=m;++i){
		int a;
		scanf("%d",&a);
		aim[i]=a;
		is[a]=1;
	}
	dfs(aim[1]);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!del[i]){
			for(int j=head[0][i];~j;j=nxt[0][j]){
				int k=point[0][j];
				if(!del[k]&&k<i){
					add(i,k,1);
					cnt++;
				}
			}
		}
	}
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int> > q;
	q.push(make_pair(aim[1],1));
	vis[aim[1]]=1;
	int maxx=0,pre=0;
	while(!q.empty()){
		pair<int,int> u=q.top();
		q.pop();
		if(u.second>maxx){
			maxx=u.second;
			pre=u.first;
		}
		else if(u.second==maxx&&u.first<pre)pre=u.first;
		for(int i=head[1][u.first];~i;i=nxt[1][i]){
			int j=point[1][i];
			if(!vis[j]){
				q.push(make_pair(j,u.second+1));
				vis[j]=1;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	q.push(make_pair(pre,1));
	vis[pre]=1;
	maxx=0;
	int ans=pre;
	while(!q.empty()){
		pair<int,int> u=q.top();
		q.pop();
		if(u.second>maxx){
			maxx=u.second;
			ans=u.first;
		}
		else if(u.second==maxx&&u.first<ans){
			ans=u.first;
		}
		for(int i=head[1][u.first];~i;i=nxt[1][i]){
			int j=point[1][i];
			if(!vis[j]){
				q.push(make_pair(j,u.second+1));
				vis[j]=1;
			}
		}
	}
	maxx--;
	ans=min(ans,pre);
	printf("%d\n%d\n",ans,maxx+(cnt-maxx)*2);
	return 0;
}
