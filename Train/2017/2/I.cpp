#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

int head[maxn],point[maxn<<1],nxt[maxn<<1],size;
int col[maxn],mcol[maxn];
int c[maxn];

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(col,0,sizeof(col));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

int n;
int ans;

void dfs(int s,int f){
	
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			scanf("%d",&c[i]);
			col[c[i]]++;
		}
		for(int i=1;i<=n;++i){
			mcol[i]=col[i];
		}
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		ans=0;
		dfs(1,-1);
		printf("%d\n",ans);
	}
	return 0;
}
