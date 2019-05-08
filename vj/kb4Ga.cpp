#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

struct cmp{
	bool operator ()(pii a,pii b){
		return a.first>b.first;
	}
};

int g[105][105],dist[105],n;

int read(){
	char c=getchar();
	while(c!='x'&&(c>'9'||c<'0'))c=getchar();
	if(c=='x')return 0x3f3f3f3f;
	int d=0;
	while(c>='0'&&c<='9'){
		d*=10;
		d+=c-'0';
		c=getchar();
	}
	return d;
}

void dij(int s){
	int i;
	memset(dist,0x3f,sizeof(dist));
	priority_queue<pii,vector<pii>,cmp>q;
	dist[s]=0;
	q.push(make_pair(dist[s],s));
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dist[u.second])continue;
		for(i=1;i<=n;i++){
			if(i!=u.second&&dist[i]>u.first+g[u.second][i]){
				dist[i]=u.first+g[u.second][i];
				q.push(make_pair(dist[i],i));
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++){
		if(dist[i]>ans)ans=dist[i];
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(g,0x3f,sizeof(g));
		int i,j;
		for(i=2;i<=n;i++){
			for(j=1;j<i;j++){
				g[i][j]=g[j][i]=read();
			}
		}
		dij(1);
	}
	return 0;
}
