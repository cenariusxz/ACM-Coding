#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn=1e5+5;

int od[maxn],fa[maxn],col[maxn];
int v[maxn];
int n,k;

void init(){
	memset(od,0,sizeof(od));
	memset(col,0,sizeof(col));
	memset(v,0,sizeof(v));
}

void solve(){
	queue<int>q;
	for(int i=1;i<=n;++i){
		if(!od[i]){
			q.push(i);
		}
	}
	int ans=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(!fa[u])continue;
		if(col[u]==0){	//white leaf
			int f=fa[u];
			if(!v[u]&&col[f]){	//black fa
				v[u]=1;
				col[f]=0;
				ans++;
			}
			od[f]--;
			if(!od[f])q.push(f);
		}
		else{			//black leaf
			int f=fa[u];
			if(!v[f]){
				v[f]=1;
				ans++;
			}
			else if(!v[u]&&col[f]){
				v[u]=1;
				col[f]=0;
				ans++;
			}
			od[f]--;
			if(!od[f])q.push(f);
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF&&(n||k)){
		init();
		for(int i=1;i<=n;++i){
			scanf("%d",&fa[i]);
			od[fa[i]]++;
		}
		for(int i=1;i<=k;++i){
			int a;
			scanf("%d",&a);
			col[a]=1;
		}
		solve();
	}
	return 0;
}
