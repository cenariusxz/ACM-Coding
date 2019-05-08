 #include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;

typedef long long ll;

const int maxn=2e3+5;
const int maxm=8e6+5;

int head[maxn],point[maxm],nxt[maxm],size;
int dis[maxn][maxn];
int n;

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(dis,-1,sizeof(dis));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void bfs(int s){
	queue<int>q;
	dis[s][s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			if(j==s)continue;
			if(dis[s][j]==-1){
				dis[s][j]=dis[s][u]+1;
				q.push(j);
			}
		}
	}
	for(int i=1;i<=n;++i)if(dis[s][i]==-1)dis[s][i]=n;
}

int main(){
	scanf("%d",&n);
	char s[maxn];
	init();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=n;++j)if(s[j]=='1')add(i,j);
	}
	for(int i=1;i<=n;++i)bfs(i);
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)ans+=dis[i][j]*(ll)dis[i][j];
	}
	cout<<ans<<endl;
}
